/*******************************************************
 *
 * Copyright (C) 2014-2015 Landoni Angel <angelland28@gmail.com>
 *
 * This file is part of corex.
 *
 * Corex can not be copied and/or distributed without the express
 * permission of Landoni Angel
 *
 *******************************************************/
 
#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <map>
#include <mutex>
#include <condition_variable>

#include "../tools/tools_string.hpp"
#include "../net/socket_server_client_handler.hpp"

// [HELPERS]
#define HTTP_SERVER_STATEGET true;
#define HTTP_SERVER_STATEPOST false;

#define HTTP_SERVER_GET "get"
#define HTTP_SERVER_POST "post"
#define HTTP_SERVER_REQUETS_MINLENGTH 10

#define HTTP_SERVER_CHAR_SPACE ' '
#define JUMPLINE '\n'
#define COLON ':'

#define GET_TOKEN_START '?'
#define GET_TOKEN_PRASE '&'
#define GET_TOKEN_ASSING '='

namespace corex{ namespace web{

class Request{
  std::string original_message; // Full request
  std::map<std::string,std::string> header_data, /*Parse Header*/
                                    cookies_,
                                    vars; // Var pass from client
  bool post_or_get;
public:
  Request(  );
  virtual ~Request(  );
  void mutate( corex::net::SocketServerClientHandler& );   // No for user use.
  void set_request( std::string );
  std::string get_cookie( std::string );
  std::string get_var( std::string );
  std::string get( std::string );
private:
  void parse_http_message(  );
};

std::vector<std::string> request_parse_get_url( std::string& );

} }

#endif
