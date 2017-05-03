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

#include "../../include/tools/tools_string.hpp"

void corex::tools::show_s( std::string _buffer ){
  std::cout<<_buffer<<std::endl;
  std::cout.flush();
}

std::string corex::tools::string_get_first_line( std::string _buffer ){
  unsigned int length_buffer = _buffer.length(  ),
  i = 0,
  j = 0;
  while( i<length_buffer ){
    if( _buffer[i] == JUMPLINE ) break;
    i++;
  }
  std::string pr0 = "";
  while( j<i ){
    pr0 += _buffer[j];
    j++;
  }
  return pr0;
}

std::vector<std::string> corex::tools::string_split( std::string _buffer,char _token ){
  unsigned int i = 0,
  j = 0,
  length_buffer = _buffer.length(  );
  std::string pr0 = "";
  std::vector<std::string> parsed_buffer;

  if( length_buffer< 3 ) return parsed_buffer;

  while( i<=length_buffer ){
    if( _buffer[i] == _token || i == length_buffer ){
      while( j<i ){
        pr0 += _buffer[j];
        j++;
      }
      j++;
      if( pr0 != "" || pr0.length(  ) > 0 )
        parsed_buffer.push_back( pr0 );
      pr0 = "";
    }
    i++;
  }
  return parsed_buffer;
}

std::vector<std::string> corex::tools::string_split_first( std::string _buffer,char _token ){
  unsigned int i = 0,j = 0, buffer_length = _buffer.length(  );
  std::vector<std::string> parsed_buffer;
  std::string pr0 = "";
  if( buffer_length< 3 ){
    parsed_buffer.push_back( "NULL" );
    parsed_buffer.push_back( "NULL" );
    return parsed_buffer;//return parsed_buffer;
  }
  while( i<buffer_length ){
    if( _buffer[i] == _token )break;
    i++;
  }
  // Copy left
  while( j<i ){
    pr0 += _buffer[j];
    j++;
  }
  if( pr0 != "" || pr0.length(  ) > 0 )
    parsed_buffer.push_back( pr0 );
  pr0 = "";
  // Right copy
  j = i+1;
  while( j<buffer_length ){
    pr0 += _buffer[j];
    j++;
  }
  if( pr0 != "" || pr0.length(  ) > 0 )
    parsed_buffer.push_back( pr0 );

  return parsed_buffer;
}

std::string corex::tools::string_to_lower( std::string _buffer ){
  std::string lower = "";
  unsigned int i = 0,buffer_length = _buffer.length(  );
  for( i = 0; i < buffer_length; ++i)
    lower += tolower( _buffer[i] );
  return lower;
}

void corex::tools::string_replace( std::string& _ref_buffer,char _tokenA,char _tokenB ){
  unsigned int buffer_length = _ref_buffer.length(  ),
                 i = buffer_length;
  while( i>0 ){
    if( _ref_buffer[i] == _tokenA )
      _ref_buffer[i] = _tokenB;
    --i;
  }
}

unsigned int corex::tools::string_count_char( std::string& _ref_buffer,char _token ){
  unsigned int buffer_length = _ref_buffer.length(  ),
                number_tokens = 0,
                i = buffer_length;
  while( i>0 ){
    if( _ref_buffer[i] == _token ) number_tokens++;
    i++;
  }
  return number_tokens;
}

void corex::tools::string_delete_char( std::string& _ref_buffer,char _token ){
  unsigned int buffer_length = _ref_buffer.length(  ),
  i = 0;
  std::string clear_buffer = "";
  while( i<buffer_length ){
    if( _ref_buffer[i] != _token ) clear_buffer += _ref_buffer[i];
    i++;
  }
  _ref_buffer = clear_buffer;
}

void corex::tools::string_delete_section( std::string& _ref_buffer,unsigned int _start,unsigned int _end ){
  if( _start > _end ) return;
  unsigned int i = 0,buffer_length=_ref_buffer.length(  );
  std::string pr0 = ""; // buffer container.
  while( i<_start ){
    pr0 += _ref_buffer[i];
    i++;
  }
  i = _end+1;
  while( i<buffer_length ){
    pr0 += _ref_buffer[i];
    i++;
  }
  _ref_buffer = pr0;
}

void corex::tools::string_inyect_buffer( std::string& _ref_buffer,std::string& _toinyect,unsigned int _position ){
  unsigned int i=0, buffer_length = _ref_buffer.length();
  std::string pr0 = "";
  while( i<=_position ){
    pr0 += _ref_buffer[i];
    ++i;
  }
  pr0 += _toinyect;
  while( i<buffer_length ){
    pr0 += _ref_buffer[i];
    ++i;
  }
  _ref_buffer = pr0;
}


unsigned int corex::tools::string_find( const std::string& _ref_buffer,char _token ){
  unsigned int i = 0,length_buffer = _ref_buffer.length(  );
  while( i<length_buffer ){
    if( _ref_buffer[i] == _token ) return i;
    i++;
  }
  return 0;
}

std::map<std::string,std::string> corex::tools::string_vector_to_map( std::vector<std::string>& _ref_vec ){
  unsigned int i = 0,size_vector = _ref_vec.size(  );
  std::map<std::string,std::string> maptemp;
  while( i<size_vector-1 ){
    maptemp[_ref_vec[i]] = _ref_vec[i+1];
    i += 2;
  }
  return maptemp;
}
