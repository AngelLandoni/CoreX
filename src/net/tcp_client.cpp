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

#include "../../include/net/tcp_client.hpp"

corex::net::TcpClient::TcpClient(  ){
  host_ = "127.0.0.1";
  port_ = SOCKET_CLIENT_PORT_DEFAULT;
  is_connected_ = false;
  is_config_ = false;
  is_created_ = false;
  create(  );
}

corex::net::TcpClient::TcpClient( const std::string _host,
                                       unsigned int _port ){
  host_ = _host;
  port_ = _port;
  is_connected_ = false;
  is_config_ = true;
  is_created_ = false;
  create(  );
}

corex::net::TcpClient::~TcpClient(  ){

}

void corex::net::TcpClient::set_target( const std::string _host,unsigned int _port ){
  host_ = _host;
  port_ = _port;
  is_config_ = true;
  is_created_ = false;
  create(  );
}

void corex::net::TcpClient::set_host( const std::string _host ){
  host_ = _host;
}

void corex::net::TcpClient::set_port( const unsigned int _port ){
  port_ = _port;
}

void corex::net::TcpClient::create(  ){
  socketFD_ = ::socket( AF_INET , SOCK_STREAM , 0 );
  if ( socketFD_ == -1 ){
    corex::tools::error_socket_no_created(  );
    return;
  }
  server_.sin_addr.s_addr = inet_addr( host_.c_str() );
  server_.sin_family = AF_INET;
  server_.sin_port = htons( port_ );
  is_created_ = true;
}

void corex::net::TcpClient::connect(  ){
  if( !is_config_ ){
    corex::tools::error_socket_no_config(  );
    return;
  }
  if( !is_created_ ){
    //corex::tools::show_s( "Is no created!." );
    return;
  }
  if( ::connect( socketFD_ , ( struct sockaddr * )&server_, sizeof( server_ ) ) < 0  ){
    corex::tools::error_socket_on_connection(  );
    ::close( socketFD_ );
    return;
  }
  is_connected_ = true;
}

void corex::net::TcpClient::connect( const std::string _host,
                                          unsigned int _port ){
  host_ = _host;
  port_ = _port;
  connect(  );
}

std::string corex::net::TcpClient::send( const std::string _buffer ){
  if( !is_connected_ ){
    corex::tools::error_socket_no_connected(  );
    return "";
  }
  if( ::send( socketFD_, _buffer.c_str(  ), strlen( _buffer.c_str(  ) ) , 0 ) < 0 ){
    corex::tools::error_socket_sending(  );
    return "";
  }
  char buffer_from_client[SOCKET_CLIENT_MAX_SIZE_BUFFER];
  bzero( buffer_from_client,SOCKET_CLIENT_MAX_SIZE_BUFFER );
  if( recv( socketFD_ , buffer_from_client, sizeof( buffer_from_client ) , 0) < 0 ){
    corex::tools::error_socket_reading(  );
    return "";
  }
  buffer_from_client[SOCKET_CLIENT_MAX_SIZE_BUFFER-1] = '\0';
  return buffer_from_client;
}

void corex::net::TcpClient::close(  ){
  ::close( socketFD_ );
}
