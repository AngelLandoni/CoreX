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

#include "../../include/net/socket_server.hpp"

// Fix it. If the socket is not created jump to listen without check. corex::SocketServer::create

corex::net::SocketServer::SocketServer(  ){
  /* Clear and set data */
  socket_status = ERROR_ON_CREATE_SOCKET;
  port = 1333;
}

corex::net::SocketServer::SocketServer( unsigned int _port,std::string _server_name ){
  /* Clear and set data */
  socket_status = ERROR_ON_CREATE_SOCKET;
  port = 1333;
}

corex::net::SocketServer::~SocketServer(  ){
  corex::tools::error_socket_client_no_disconected( "corex::Socket::~Socket",ACLARATION_MSG_SENDEDABORTED );
  close( socket_status );
}

void corex::net::SocketServer::set_options( unsigned int _value ){

}

corex::tools::Error corex::net::SocketServer::create(  ){
  socket_status = socket( AF_INET,SOCK_STREAM,0 );
  if( socket_status == ERROR_ON_CREATE_SOCKET ){
    error_handler.set( 1,ERROR_MSG_NOCRETESOCKET );
  }
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons( port );

  // Bind
  if( bind( socket_status,(struct sockaddr*)&server,sizeof(server)) < 0 ){
    error_handler.set( 2,ERROR_MSG_NOBINDSOCKET );
    return error_handler;
  }

  ::listen( socket_status,3 );

  return error_handler;
}

corex::net::SocketServerClientHandler corex::net::SocketServer::listen(  ){
  corex::net::SocketServerClientHandler newclient;
  newclient.set_socket( accept( socket_status,
  (struct sockaddr *)newclient.get_ptr_client(  ),
  (socklen_t*)newclient.get_client_socket_size(  ) ) );
  int read_size = 0;
  char buffer_temp[MAX_SIZE_BUFFER_FROM_CLIENT];
  read_size = recv( newclient.get_socket(  ),buffer_temp,MAX_SIZE_BUFFER_FROM_CLIENT,0 );
  buffer_temp[read_size] = '\0';


  newclient.set_message( std::string( buffer_temp ) );
  newclient.set_size_message( read_size );

  return newclient;
}

void corex::net::SocketServer::send_to_client( corex::net::SocketServerClientHandler& _ref_client,std::string _buffer ){
  if( _ref_client.get_status(  ) == NO_CONNECTED ){
    corex::tools::error_socket_client_no_disconected( "corex::net::Socket::send_to_client",
                                                    ACLARATION_MSG_SENDEDABORTED );
    return;
  }
  write( _ref_client.get_socket(  ),_buffer.c_str(  ),strlen(_buffer.c_str(  ) ) );
}

// No tested !!!!!!! WARNING
void corex::net::SocketServer::send_to_client( corex::net::SocketServerClientHandler& _ref_client,char* _buffer ){
  if( _ref_client.get_status(  ) == NO_CONNECTED ){
    corex::tools::error_socket_client_no_disconected( "corex::net::Socket::send_to_client",
                                                     ACLARATION_MSG_SENDEDABORTED );
    return;
  }
  write( _ref_client.get_socket(  ),_buffer,strlen( _buffer ) );
}

void corex::net::SocketServer::send_to_client( corex::net::SocketServerClientHandler& _ref_client,char* _buffer , unsigned int _size){
  if( _ref_client.get_status(  ) == NO_CONNECTED ){
    corex::tools::error_socket_client_no_disconected( "corex::net::Socket::send_to_client",
                                                     ACLARATION_MSG_SENDEDABORTED );
    return;
  }

  write( _ref_client.get_socket(  ),_buffer,_size );
}

void corex::net::SocketServer::disconnect_client( corex::net::SocketServerClientHandler& _ref_client  ){
  _ref_client.set_status( NO_CONNECTED );
  close( _ref_client.get_socket(  ) );
}


// [Primitives]
// FIX DONT HABE SET NAMESPACE
void corex::net::corex_socketserver_send_to_client( corex::net::SocketServerClientHandler& _ref_client ,std::string _buffer ){
  if( _ref_client.get_status(  ) == NO_CONNECTED ){
    corex::tools::error_socket_client_no_disconected( "corex_socket_send_to_client",ACLARATION_MSG_SENDEDABORTED );
    return;
  }
  write( _ref_client.get_socket(  ),_buffer.c_str(  ),strlen(_buffer.c_str(  ) ) );
}
