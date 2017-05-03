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

#ifndef REDIS_CLIENT_HPP
#define REDIS_CLIENT_HPP

#include "../net/tcp_client.hpp"
#include "../tools/error_functions.hpp"

// #define REDIS_CLIENT_DEBUG
// If the directive RC_DEBUG is created this set the redis client in debug mode!.

#define REDISCLIENT_DEFAULT_PORT 6379
#define REDISCLIENT_DEFAULT_HOST "127.0.0.1"

#define REDISCLIENT_OK "+OK\r\n"

namespace corex{ namespace database{

class RedisClient{
    std::string host_;
    unsigned int port_,
                   time_out_;
    corex::net::TcpClient conn_;
    bool is_connected;
  public:
    RedisClient(  );
    RedisClient( const std::string,unsigned int );                // HOST PORT
    RedisClient( const std::string,unsigned int,unsigned int ); // HOST PORT TIME_OUT
    ~RedisClient(  );
    void set_host( const std::string );
    void set_port( const unsigned int );
    bool set( const std::string,const std::string );               // KEY VALUE
    void del( const std::string );
    void connect(  );
    void connect( const std::string,unsigned int );                // HOST PORT
    void connect( const std::string,unsigned int,unsigned int ); // HOST PORT TIME_OUT
    bool ping(  );                                                   // If return true when recive a pong ( depend timeout ) else return false
    void close(  );
};

} }


#endif
