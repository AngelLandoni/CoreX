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

#include "../../include/web/html.hpp"

corex::web::Html::Html(  ){
  path_file_ = "";
  is_file_load = false;
  memblock = NULL;
  memblock_size = 0;
}

corex::web::Html::Html( std::string _path_file ){
  memblock = NULL;
  load_file( _path_file );
  is_file_load = true;
  memblock_size = 0;
}

corex::web::Html::Html( std::string _path_file,std::map<std::string,std::string>& _to_replace ){
  load_file( _path_file );
  maping( _to_replace );
  is_file_load = true;
  memblock_size = 0;
}

corex::web::Html::~Html(  ){
  if( memblock != NULL )
    delete[] memblock;
  }

void corex::web::Html::load_file( std::string& _ref_path_file ){
  path_file_ = _ref_path_file;
  std::string buffer = corex::tools::b_load_file( _ref_path_file );
  memblock_size = buffer.length(  );
  memblock = new char[memblock_size];
  memset ( memblock,'\0',memblock_size );
  strcpy( memblock, buffer.c_str() );
  memblock[memblock_size] = END_OF_LINE;
}

void corex::web::Html::load_file( std::string& _name_file,std::map<std::string,std::string>& _to_replace ){
  is_file_load = true;
  load_file( _name_file );
  maping( _to_replace );
}

void corex::web::Html::set_content( const std::string _buffer ){
  memblock_size = _buffer.length(  );
  if( memblock != NULL ){
    delete[] memblock;
    memblock = new char[ memblock_size+1 ];
  }else memblock = new char[ memblock_size+1 ];
  strcpy( memblock,_buffer.c_str(  ) );
  memblock[memblock_size] = '\0';
}

void corex::web::Html::set_content( const std::string& _ref_buffer ){
  memblock_size = _ref_buffer.length(  );
  if( memblock != NULL ){
    delete[] memblock;
    memblock = new char[ memblock_size+1 ];
  }else memblock = new char[ memblock_size+1 ];
  strcpy( memblock,_ref_buffer.c_str(  ) );
  memblock[memblock_size] = '\0';
}

void corex::web::Html::maping( std::map<std::string,std::string>& _ref_map ){
  unsigned int i = 0, j = 0;
  std::string pr0 = "",  /* Contain the var 's name to rempalce */
  copy_memblock = std::string( memblock );

  while( i<memblock_size ){
    if( copy_memblock[i] == MAPING_TOKEN_BEGIN &&
        copy_memblock[i+1] == MAPING_TOKEN_BEGIN ){

      j = i; // BEGIN TOKEN FLAG
      i+=2; // JUMP LAST CHARACTER
      while( i<memblock_size ){
        if( copy_memblock[i] == MAPING_TOKEN_END &&
        copy_memblock[i+1] == MAPING_TOKEN_END ) break;

        pr0 += copy_memblock[i];
        i++;
      }
      i++; // JUMP TO THE END OF THE TOKENS

      corex::tools::string_inyect_buffer( copy_memblock,_ref_map[pr0],j-1 );
      corex::tools::string_delete_section( copy_memblock,_ref_map[pr0].length(  )+j,_ref_map[pr0].length(  )+i );
      pr0 = "";
      continue;
    }
  i++;
  }

  memblock = new char[copy_memblock.length(  )];
  strcpy( memblock, copy_memblock.c_str() );
}

unsigned int corex::web::Html::get_size_memblock(  ){
  return memblock_size;
}

std::string corex::web::Html::get_memblock(  ){
  if( memblock == NULL ) return "";
  return  memblock;
}
