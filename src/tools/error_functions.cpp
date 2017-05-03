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

#include "../../include/tools/error_functions.hpp"

void corex::tools::error_socket_client_no_disconected( std::string _invokerFunction,std::string _aclaration ){
  corex::tools::show_s( _invokerFunction+" -> "+std::string( WARNING_MSG_CLIENTNODISCONNECTED )+" : "+_aclaration );
}

void corex::tools::error_httpserver_nullworkers(  ){
  corex::tools::show_s( HTTPSERVER_ERROR_MSG_NULLWORKERS );
}

void corex::tools::error_file_no_exist( std::string _path_file ){
  //corex::tools::show_s( ERROR_FILE_NO_EXIST( _path_file );
  std::cout<<"The file no exist ( "<<_path_file<<" )"<<std::endl;
}

void corex::tools::error_bad_memory_allocation(  ){
  corex::tools::show_s( BAD_MEMORY_ALLOCATION );
}

void corex::tools::error_socket_bind(  ){
  corex:tools::show_s( ERROR_BINDING );
}

void corex::tools::error_socket_on_connection(  ){
  corex::tools::show_s( ERROR_ON_CREATE_SOCKET_CONNECTION );
}

void corex::tools::error_socket_no_config(  ){
  corex::tools::show_s( ERROR_NO_CONFIG );
}

void corex::tools::error_socket_no_created(  ){
  corex::tools::show_s( ERROR_ON_CREATE_SOCKET_CONNECTION );
}

void corex::tools::error_socket_no_valid_address_family(  ){
  corex::tools::show_s( ERROR_WRONG_FAMILY_ADDRESS );
}

void corex::tools::error_socket_no_valid_ipaddress(  ){
  corex::tools::show_s( ERROR_NO_VALID_IPADDRESS );
}

void corex::tools::error_http_server_response_bad_cookie(  ){
  corex::tools::show_s( HTTPSERVERREQUEST_ERROR_MSG_BADCOOKIE );
}

void corex::tools::error_socket_sending(  ){
  corex::tools::show_s( ERROR_SENDING_DATA );
}

void corex::tools::error_socket_reading(  ){
  corex::tools::show_s( ERROR_READING_DATA );
}

void corex::tools::error_socket_no_connected(  ){
  corex::tools::show_s( ERROR_NO_CONNECTED );
}

void corex::tools::error_redisclient_no_connected(  ){
  corex::tools::show_s( ERROR_REDISCLIENT_NO_CONNECTED );
}
