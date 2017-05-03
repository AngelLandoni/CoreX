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

#include "../../include/web/request.hpp"

corex::web::Request::Request(  ){
  post_or_get = HTTP_SERVER_STATEGET;
}

corex::web::Request::~Request(  ){

}

void corex::web::Request::mutate( corex::net::SocketServerClientHandler& _ref_client ){
  set_request( _ref_client.get_message(  ) );
}

void corex::web::Request::set_request( std::string _buffer_message ){
  if( _buffer_message.length( ) < HTTP_SERVER_REQUETS_MINLENGTH ) return;
  original_message = _buffer_message;
  parse_http_message(  );
}

std::string corex::web::Request::get_cookie( std::string _key ){
  return cookies_[ _key ];
}

std::string corex::web::Request::get_var( std::string _value ){
  return vars[_value];
}

std::string corex::web::Request::get( std::string _value ){
  return header_data[_value];
}

// [PRIVATE FUNCTIONS]
void corex::web::Request::parse_http_message(  ){
  unsigned int i = 0;

  std::vector<std::string> firstlineparsed = corex::tools::string_split( corex::tools::string_get_first_line( original_message ),HTTP_SERVER_CHAR_SPACE );
  if( corex::tools::string_to_lower( firstlineparsed[0] ) == HTTP_SERVER_POST ||
      corex::tools::string_to_lower( firstlineparsed[0] ) == HTTP_SERVER_GET ){
        if( firstlineparsed[0] == HTTP_SERVER_POST )
          post_or_get = HTTP_SERVER_STATEPOST;
        header_data.insert( std::pair<std::string,std::string>( "method",corex::tools::string_to_lower( firstlineparsed[0] ) ) );
  }else{
    return; // SHOW ERROR!.
  }


  if( firstlineparsed[0] == "" ) return;

  std::string tempurl = firstlineparsed[1];

  if( corex::tools::string_to_lower( firstlineparsed[0] ) == HTTP_SERVER_GET &&
      corex::tools::string_find( tempurl,GET_TOKEN_START ) != 0 ){
    // USE VAR [i]
    std::vector<std::string> parameters = corex::web::request_parse_get_url( firstlineparsed[1] );
    unsigned int length_parameters = parameters.size(  );

    for( i=0;i<length_parameters;i+=2 )
      vars.insert( std::pair<std::string,std::string>( parameters[i],parameters[i+1] ) );
    // NOT USER VAR [i]

    corex::tools::string_delete_section( tempurl,
                                         corex::tools::string_find( tempurl,GET_TOKEN_START ),
                                         tempurl.length(  ) );

    header_data.insert( std::pair<std::string,std::string>( "url",tempurl ) );
  }else
    header_data.insert( std::pair<std::string,std::string>( "url",firstlineparsed[1] ) );

  header_data.insert( std::pair<std::string,std::string>( "http_version",firstlineparsed[2] ) );

  std::vector<std::string> header_lines = corex::tools::string_split( original_message,JUMPLINE );

  unsigned int array_length = header_lines.size(  );

  // USE VAR [i]
  i = 1; // Jump the first line
  while( i<array_length-2 ){
    if( header_lines[i] == "" || header_lines[i] == "" ||
        header_lines[i] == "\n" || header_lines[i] == "\n" ){
      i++;
      continue;
    }
    std::vector<std::string> items = corex::tools::string_split_first( header_lines[i],COLON );
    header_data.insert( std::pair<std::string,std::string>( corex::tools::string_to_lower( items[0] ),items[1] ) );
    i++;
  }

  // NOT USER VAR [i]

  //[Parse cookies]
  std::string buffer_cookies = header_data["cookie"];
  corex::tools::string_replace( buffer_cookies,';','=' );
  std::vector<std::string> parse_buffer_cookies = corex::tools::string_split( buffer_cookies,'=' );

  unsigned int length_parse_buffer_cookies = parse_buffer_cookies.size( );

  // USE VAR [i]
  i = 0;
  while( i<length_parse_buffer_cookies ){
    corex::tools::string_delete_char( parse_buffer_cookies[i] , ' ' );
    cookies_.insert( std::pair<std::string,std::string>( parse_buffer_cookies[i],
    parse_buffer_cookies[i+1] ) );
    i+=2;
  }
  // NOT USE VAR [i]

  // Check header type, if it a post parse send data
  if( header_data["method"] == HTTP_SERVER_POST ){
    std::string parameters = header_lines.back(  );
    corex::tools::string_replace( parameters,'&','=' );
    std::vector<std::string> parsed_parameters = corex::tools::string_split( parameters,'=' );
    vars = corex::tools::string_vector_to_map( parsed_parameters );
  }
}

// FUNCTIONS
std::vector<std::string> corex::web::request_parse_get_url( std::string& _buffer ){
  corex::tools::string_delete_section( _buffer,0,corex::tools::string_find( _buffer,GET_TOKEN_START ) );
  corex::tools::string_replace( _buffer,GET_TOKEN_PRASE,GET_TOKEN_ASSING );
  return corex::tools::string_split( _buffer,GET_TOKEN_ASSING );
}
