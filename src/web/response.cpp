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

#include "../../include/web/response.hpp"

corex::web::Response::Response(  ){
  content_ = NULL;
  type_ = HTTP_HTML;
  server_name_ = "corex";
  response_code_ = corex::web::NONE;
}

corex::web::Response::Response( char _type,std::string _content ){
  content_ = NULL;
}

corex::web::Response::~Response(  ){
  delete[] content_;
}

void corex::web::Response::set_cookie( std::string _key,std::string _value ){
  if( _key == "" ){
    corex::tools::error_http_server_response_bad_cookie(  );
    return;
  }
  cookies_.insert( std::pair<std::string,std::string>( _key,_value ) );
}

// HTML Content
// ARREGLAR MUY TRUCHO
void corex::web::Response::send( corex::web::Html& _ref_html ){
  std::string memblock = _ref_html.get_memblock(  );
  type_ = HTTP_HTML;

  size_content_ = memblock.length(  );

  content_ = new char[size_content_];
  memcpy( content_,memblock.c_str(  ),size_content_ );

  response_code_ = corex::web::OK;
}

// JAVASCRIPT Content
void corex::web::Response::send( corex::web::Javascript& _ref_javascript ){
  std::string memblock = _ref_javascript.get_memblock(  );
  type_ = HTTP_JS;

  size_content_ = memblock.length(  );

  content_ = new char[size_content_];
  memcpy( content_,memblock.c_str(  ),size_content_ );

  response_code_ = corex::web::OK;
}

// CSS Content
void corex::web::Response::send( corex::web::Css& _ref_css ){
  std::string memblock = _ref_css.get_memblock(  );
  type_ = HTTP_CSS;

  size_content_ = memblock.length(  );

  content_ = new char[size_content_];
  memcpy( content_,memblock.c_str(  ),size_content_ );

  response_code_ = corex::web::OK;
}

void corex::web::Response::send( corex::graphics::Image& _ref_image ){
  content_ = new char[_ref_image.get_size_memblock(  )];
  memcpy( content_,_ref_image.get_memblock(  ),_ref_image.get_size_memblock(  ) );

  size_content_ = _ref_image.get_size_memblock(  );

  if( _ref_image.get_type(  ) == IMAGE_JPG ) type_ = HTTP_JPG;
  else if( _ref_image.get_type(  ) == IMAGE_PNG ) type_ = HTTP_PNG;
  else if( _ref_image.get_type(  ) == IMAGE_BMP ) type_ = HTTP_BMP;

    //Extend for other images
  response_code_ = corex::web::OK;
}

void corex::web::Response::redirect( const std::string _url ){
  response_code_ = corex::web::REDIRECT;
  size_content_ = _url.length(  );
  content_ = new char[ size_content_ ];
  memcpy( content_,_url.c_str(  ),size_content_ );

  response_code_ = corex::web::REDIRECT;
}

corex::tools::DynamicMemory* corex::web::Response::get_packet(  ){
  corex::tools::DynamicMemory* mem = new corex::tools::DynamicMemory;

  if( response_code_ == corex::web::NONE ){
    mem->push( "HTTP/1.0 200 OK\n" );
    mem->push( "Server: " );
    mem->push( server_name_.c_str(  ) );
    mem->push( "\n" );
    mem->push( "Content-type: text/html\n" );
    mem->push( "Content-type: 0" );
    mem->push( "\n\n" );
    return mem;
  }

  if( response_code_ == corex::web::OK ){
    mem->push( "HTTP/1.0 200 OK\n" );
    mem->push( "Server: " );
    mem->push( server_name_.c_str(  ) );
    mem->push( "\n" );
    mem->push( "Content-type: " );

    if( type_ == HTTP_HTML ) mem->push( "text/html\n" );
    else if( type_ == HTTP_CSS ) mem->push( "text/css\n" );
    else if( type_ == HTTP_JS ) mem->push( "text/javascript\n" );
    else if( type_ == HTTP_JPG ) mem->push( "image/jpg\n" );
    else if( type_ == HTTP_PNG ) mem->push( "image/png\n" );
    else mem->push( "text/html\n" );

    if( cookies_.size(  ) >0 ){
      mem->push( "Set-Cookie: " );
      for( auto& item: cookies_ ){
        mem->push( item.first.c_str(  ) );
        mem->push( "=" );
        mem->push( item.second.c_str(  ) );
        mem->push( ";" );
      }
      mem->push( "\n" );
    }

    mem->push( "Content-Length: " );
    mem->push( std::to_string( size_content_ ).c_str(  ) );
    mem->push( "\n\n" );

    mem->push( content_,size_content_ );

    mem->push( '\0' );
    return mem;
  }else if( response_code_ == corex::web::REDIRECT ){
    mem->push( "HTTP/1.0 301 Moved Permanently\n" );
    mem->push( "Location: " );
    mem->push( content_,size_content_ );
    mem->push( "\n\n" );
    mem->push( '\0' );
    return mem;
  }

  return mem;
}
