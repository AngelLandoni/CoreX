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

#ifndef ERROR_FUNCTIONS_HPP
#define ERROR_FUNCTIONS_HPP

#include "tools_string.hpp"

#define WARNING_MSG_CLIENTNODISCONNECTED "[Warning] This client is not disconnected."

// [HTTPSERVER]
#define HTTPSERVER_ERROR_MSG_NULLWORKERS "[Error] Null workers!."

//[HTTPSERVERREQUEST]
#define HTTPSERVERREQUEST_ERROR_MSG_BADCOOKIE "[Error] The cookie is invalid."

//[ERRORS]
#define ERROR_FILE_NO_EXIST( parameter ) "[Error] "#parameter
#define BAD_MEMORY_ALLOCATION "[Error] Bad memory allocation!."
#define ERROR_ON_CREATE_SOCKET_CONNECTION "[Error] Creating socket!."
#define ERROR_WRONG_FAMILY_ADDRESS "[Error] First parameter is not a valid address family!."
#define ERROR_NO_VALID_IPADDRESS "[Error] No valid ip address!."
#define ERROR_NO_CONFIG "[Error] Wrong host or port?."
#define ERROR_BINDING "[Error] Binding socket. Port is used?."
#define ERROR_SENDING_DATA "[Error] Sending data!."
#define ERROR_READING_DATA "[Error] Reading data!."
#define ERROR_NO_CONNECTED "[Error] Socket is not connected!."
#define ERROR_REDISCLIENT_NO_CONNECTED "[Error] Redis client is not connected!."

namespace corex{ namespace tools{

void error_socket_client_no_disconected( std::string,std::string );
void error_httpserver_nullworkers(  );
void error_file_no_exist( std::string );
void error_bad_memory_allocation(  );
void error_socket_bind(  );
void error_socket_on_connection(  );
void error_socket_no_config(  );
void error_socket_no_created(  );
void error_socket_no_valid_address_family(  );
void error_socket_no_valid_ipaddress(  );
void error_socket_sending(  );
void error_socket_reading(  );
void error_socket_no_connected(  );

void error_redisclient_no_connected(  );

void error_http_server_response_bad_cookie(  );

} }


#endif
