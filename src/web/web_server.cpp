/*
 * Copyright (C) 2014-2015 Landoni Angel <angelland28@gmail.com>
 *
 * CoreX is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CoreX is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../include/web/web_server.hpp"

// Constructor
corex::web::WebServer::WebServer(  ){
  listen( WEBSERVER_DEFAULT_PORT,WEBSERVER_DEFAULT_NUMWORKERS );
}

corex::web::WebServer::WebServer( unsigned int _port,unsigned int _num_workers ){
  listen( _port,_num_workers );
}

// Destructor
corex::web::WebServer::~WebServer(  ){

}

void corex::web::WebServer::listen( unsigned int _port,unsigned int _num_workers ){
  error = false;
  if( _num_workers == 0 ){
    error = true;
    corex::tools::error_httpserver_nullworkers(  );
    return;
  }
  port = _port;
  num_workers = _num_workers;
  ptr_router_ = NULL;
}

void corex::web::WebServer::run( void( *_incoming_callback )(  ),
                                     corex::web::Response( *_http_request )( corex::web::Request& _req ) ){
  if( error ) return; // jump if the workers are wrong!

  create_workers( num_workers );

  if( socket_server_handler.create(  ).get_id(  ) == ERROR_SOCKETSERVER_MSG_PORTUSED ){
    corex::tools::error_socket_bind(  );
    return;
  }
  http_request = _http_request;
  std::thread socket_connections_thread( [&](  ){
    while( true ){
      clients.push( socket_server_handler.listen(  ) );
      _incoming_callback(  );
    }
  } );
  socket_connections_thread.join();
  // Start the workers!.
  unsigned int i = 0;
  while( i<num_workers ){
    workers[i].join(  );
    i++;
  }
}

bool corex::web::WebServer::run( corex::web::Router& _ref_router ){
  if( error ) return false;

  create_workers_router(  );

  if( socket_server_handler.create(  ).get_id(  ) == ERROR_SOCKETSERVER_MSG_PORTUSED ){
    corex::tools::error_socket_bind(  );
    return false;
  }

  ptr_router_ = &_ref_router;

  std::thread socket_connections_thread( [&](  ){
    while( true )
      clients.push( socket_server_handler.listen(  ) );
  } );

  socket_connections_thread.join();
  // Start the workers!.
  unsigned int i = 0;
  while( i<num_workers ){
    workers[i].join(  );
    i++;
  }

  return true;
}

// [PRIVATE FUNCTIONS]

void corex::web::WebServer::create_workers( unsigned int _num_workers ){
  unsigned int i = 0;
  while( i<num_workers ){
    workers.push_back( std::thread( [&](  ){

      corex::net::SocketServerClientHandler client_temp;


      while( true ){
        if( !clients.is_empty(  ) ){

          corex::web::Request client_request;

          client_temp = clients.pop(  );
          client_request.mutate( client_temp );

          corex::tools::DynamicMemory * ptrmem = http_request( client_request ).get_packet(  );

          socket_server_handler.send_to_client( client_temp,ptrmem->get(  ),ptrmem->get_size(  ) );
          socket_server_handler.disconnect_client( client_temp );

          delete ptrmem;
        }else{
          std::this_thread::sleep_for( std::chrono::milliseconds( HTTPSERVER_DEATHTIME_WORKERS ) );
        }
      }

    } ) );
    i++;
  }
}


void corex::web::WebServer::create_workers_router(  ){
  unsigned int i = 0;
  while( i<num_workers ){
    workers.push_back( std::thread( [&](  ){
      corex::net::SocketServerClientHandler client_temp;

      while( true ){
        if( !clients.is_empty(  ) ){

          corex::web::Request client_request;

          client_temp = clients.pop(  );
          client_request.mutate( client_temp );

          corex::web::Response res;
          ptr_router_->process( client_request,res );
          corex::tools::DynamicMemory * ptrmem = res.get_packet(  );

          socket_server_handler.send_to_client( client_temp,ptrmem->get(  ),ptrmem->get_buffer_size(  ) );
          socket_server_handler.disconnect_client( client_temp );

          delete ptrmem;
        }else{
          std::this_thread::sleep_for( std::chrono::milliseconds( HTTPSERVER_DEATHTIME_WORKERS ) );
        }
      }

    } ) );
    i++;
  }
}
