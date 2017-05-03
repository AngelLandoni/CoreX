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

#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>    //write

#include "socket_server_client_handler.hpp"
#include "../tools/tools_string.hpp"
#include "../tools/error.hpp"
#include "../tools/error_functions.hpp"

// [HELPERS]

// [Errors]
#define ERROR_ON_CREATE_SOCKET -1
#define ERROR_MSG_NOCRETESOCKET "Error on create Socket." // Error id:1
#define ERROR_MSG_NOBINDSOCKET  "Error on bind server."   // Error id:2

// [WARNINGS]

// [ACLARATIONS]
#define ACLARATION_MSG_SENDEDABORTED "sending aborted."

// [ERRORS]
#define ERROR_SOCKETSERVER_MSG_PORTUSED 2

namespace corex{ namespace net{

class SocketServer{
  int socket_status;
  unsigned int port;
  struct sockaddr_in server,client;
  corex::tools::Error error_handler;
  std::string server_name;
public:
  SocketServer(  );
  SocketServer( unsigned int,std::string );          // Port, Server Name,
  virtual ~SocketServer(  );
  void set_options( unsigned int );
  corex::tools::Error create(  );
  SocketServerClientHandler listen(  );
  void send_to_client( SocketServerClientHandler&,std::string );
  void send_to_client( SocketServerClientHandler&,char* );
  void send_to_client( SocketServerClientHandler&,char*,unsigned int );
  void disconnect_client( SocketServerClientHandler& );
};

// Primitive sending.
void corex_socketserver_send_to_client( SocketServerClientHandler&,std::string );

} }

#endif
