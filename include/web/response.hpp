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

#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <map>
#include <cstring>

#include "../tools/tools_string.hpp"
#include "../tools/error_functions.hpp"
#include "../tools/dynamic_memory.hpp"
#include "../web/html.hpp"
#include "../web/javascript.hpp"
#include "../web/css.hpp"
#include "../graphics/2d/image.hpp"

// [HELPERS]
enum{
  HTTP_HTML,
  HTTP_CSS,
  HTTP_JS,
  HTTP_JPG,
  HTTP_PNG,
  HTTP_BMP
};

#define HTTP_SERVER_RESPONSE_SETCOOKIE "Set-Cookie"
#define HTTP_SERVER_MAX_SIZE_HEADER 800

namespace corex{ namespace web{

enum RESPONSECODE{
  NONE,
  OK,
  REDIRECT
};

class Response{
  std::string server_name_; // name server no server name!
  char * content_;
  unsigned int size_content_;
  unsigned char type_;
  std::map<std::string,std::string> cookies_;
  unsigned short response_code_;
public:
  Response(  );
  Response( char,std::string );
  virtual ~Response(  );
  void server_name( std::string );
  void set_cookie( std::string,std::string );
  void send( corex::web::Html& );
  void send( corex::web::Javascript& );
  void send( corex::web::Css& );
  void send( corex::graphics::Image& );
  void redirect( const std::string );

  corex::tools::DynamicMemory* get_packet(  );
};

} }

#endif
