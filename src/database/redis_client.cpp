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

#include "../../include/database/redis_client.hpp"

corex::database::RedisClient::RedisClient(  ){
  host_ = REDISCLIENT_DEFAULT_HOST;
  port_ = REDISCLIENT_DEFAULT_PORT;
  conn_.set_target( REDISCLIENT_DEFAULT_HOST,REDISCLIENT_DEFAULT_PORT );
  is_connected = false;
}

corex::database::RedisClient::RedisClient( const std::string _host,
                                                 unsigned int _port ){
  host_ = _host;
  port_ = _port;
  conn_.set_target( _host,_port );
  is_connected = false;
}

corex::database::RedisClient::RedisClient( const std::string _host,
                                                 unsigned int _port,
                                                 unsigned int _time_out ){
  // _time_out NO USED!.
  host_ = _host;
  port_ = _port;
  time_out_ = _time_out;
  conn_.set_target( _host,_port );
  is_connected = false;
}

corex::database::RedisClient::~RedisClient(  ){
  //conn_.close(  );
}

void corex::database::RedisClient::set_host( const std::string _host ){
  host_ = _host;
  conn_.set_host( host_ );
}

void corex::database::RedisClient::set_port( const unsigned int _port ){
  port_ = _port;
  conn_.set_port( port_ );
}

bool corex::database::RedisClient::set( const std::string _key,
                                              const std::string _value ){
  // *3\r\n$3\r\nSET\r\n$5\r\nmykey\r\n$8\r\nmy value\r\n
  if( !is_connected ){
    corex::tools::error_redisclient_no_connected(  );
    return false;
  }
  std::string query = "*3\r\n$3\r\nSET\r\n$";
  query += std::to_string( _key.length(  ) );
  query += "\r\n"+_key+"\r\n$";
  query += std::to_string( _value.length(  ) );
  query += "\r\n"+_value+"\r\n";

  if( conn_.send( query ) == REDISCLIENT_OK ) return true;
  return false;
}

void corex::database::RedisClient::del( const std::string ){

}

void corex::database::RedisClient::connect(  ){
  conn_.connect( host_,port_ );
  is_connected = true;
}

void corex::database::RedisClient::connect( const std::string _host,
                                                  unsigned int _port ){

}

void corex::database::RedisClient::connect( const std::string _host,
                                                  unsigned int _port,
                                                  unsigned int _time_out ){

}

bool corex::database::RedisClient::ping(  ){
  return false;
}

void corex::database::RedisClient::close(  ){
  conn_.close(  );
}
