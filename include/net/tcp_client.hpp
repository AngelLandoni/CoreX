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

#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP

#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>    //write
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../tools/tools_string.hpp"
#include "../tools/error_functions.hpp"

#define SOCKET_CLIENT_PORT_DEFAULT 1334
#define SOCKET_CLIENT_MAX_SIZE_BUFFER 10000

namespace corex{ namespace net{

class TcpClient{
  std::string host_;
  unsigned int port_;
  bool is_connected_,is_config_,is_created_;
  struct sockaddr_in server_;
  int response_, socketFD_;
public:
  TcpClient(  );
  TcpClient( const std::string,unsigned int );
  ~TcpClient(  );
  void set_target( const std::string,unsigned int );
  void set_host( const std::string );
  void set_port( const unsigned int );
  void create(  );
  void connect(  );
  void connect( const std::string,unsigned int );
  std::string send( const std::string );
  void close(  );
};

} }

#endif
