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

#include "../../include/net/socket_server_client_handler.hpp"

corex::net::SocketServerClientHandler::SocketServerClientHandler(  ){
  socket_size = sizeof( struct sockaddr_in );
}

corex::net::SocketServerClientHandler::~SocketServerClientHandler(  ){
  /*if( status_connection == CONNECTED )
  show_s( WARNING_MSG_CLIENTNODISCONNECTED );*/
}

void corex::net::SocketServerClientHandler::set_socket( unsigned int _sock ){
  socket = _sock;
  status_connection = CONNECTED;
  if( socket < 0 )
    return; // ERROR
}

int corex::net::SocketServerClientHandler::get_socket(  ){
  return socket;
}

void corex::net::SocketServerClientHandler::set_message( std::string _buffer ){
  message = _buffer;
}

std::string corex::net::SocketServerClientHandler::get_message(  ){
  return message;
}

void corex::net::SocketServerClientHandler::set_size_message( unsigned int _value ){
  size_message = _value;
}

struct sockaddr_in* corex::net::SocketServerClientHandler::get_ptr_client(  ){
  return &client_sock;
}

int* corex::net::SocketServerClientHandler::get_client_socket_size(  ){
  return &socket_size;
}

void corex::net::SocketServerClientHandler::set_status( bool _status ){
  status_connection = _status;
}

bool corex::net::SocketServerClientHandler::get_status(  ){
  return status_connection;
}
