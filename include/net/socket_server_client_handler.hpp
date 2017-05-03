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

#ifndef SOCKET_SERVER_CLIENT_HANDLER_HPP
#define SOCKET_SERVER_CLIENT_HANDLER_HPP

#include <arpa/inet.h>

#include "../tools/tools_string.hpp"
#include "../tools/error_functions.hpp"

// [HELPERS]
#define NO_CONNECTED false
#define CONNECTED true
#define MAX_SIZE_BUFFER_FROM_CLIENT 10000

namespace corex{ namespace net{

class SocketServerClientHandler{
  int socket,socket_size,size_message;
  struct sockaddr_in client_sock;
  std::string message;
  bool status_connection;
public:
  SocketServerClientHandler(  );
  virtual ~SocketServerClientHandler(  );
  void set_socket( unsigned int );
  int get_socket(  );
  void set_message( std::string );
  std::string get_message(  );
  void set_size_message( unsigned int );
  struct sockaddr_in* get_ptr_client(  );
  int* get_client_socket_size(  );
  void set_status( bool );                    // Set connected or disconnected
  bool get_status(  );                        // Is connected or disconnected
};

} }


#endif
