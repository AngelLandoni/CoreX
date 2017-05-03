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

#ifndef WEB_SERVER_HPP
#define WEB_SERVER_HPP

#include <thread>
#include <mutex>
#include <vector>
#include <functional>

#include "../net/socket_server.hpp"
#include "../web/request.hpp"
#include "../web/response.hpp"
#include "../web/html.hpp"
#include "../web/javascript.hpp"
#include "../web/css.hpp"
#include "../web/router.hpp"
#include "../tools/concurrent_queue.hpp"                        // CQueue use tempaltes
#include "../../src/tools/concurrent_queue.cpp"               // CQueue use tempaltes
#include "../tools/error_functions.hpp"

// [Helpers]
#define HTTPSERVER_DEATHTIME_WORKERS 100
#define WEBSERVER_DEFAULT_PORT 1333
#define WEBSERVER_DEFAULT_NUMWORKERS 2

namespace corex{ namespace web{

class WebServer{
  corex::net::SocketServer socket_server_handler;
  std::vector<std::thread> workers;
  corex::tools::CQueue<corex::net::SocketServerClientHandler> clients;
  unsigned int num_workers,
                 port;
  corex::web::Router* ptr_router_;
  corex::web::Response (*http_request)( corex::web::Request& );
  std::mutex callback_mutex_;
  bool error;
public:
  WebServer(  );
  WebServer( unsigned int,unsigned int );
  virtual ~WebServer(  );
  void listen( unsigned int,unsigned int );
  void run( void(*)(  ),corex::web::Response(*)( corex::web::Request& ) );
  bool run( corex::web::Router& );
private:
  void create_workers( unsigned int );
  void create_workers_router(  );
};

} }

#endif
