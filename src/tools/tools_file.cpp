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

#include "../../include/tools/tools_file.hpp"

std::string corex::tools::b_load_file( std::string& _ref_path_file ){
  char * temp_buffer;
  unsigned int size_temp_buffer;
  std::ifstream file( _ref_path_file, std::ios::in|std::ios::binary|std::ios::ate );

  if ( !file.is_open( ) ){
    corex::tools::error_file_no_exist( _ref_path_file );
    return "";
  }

  file.seekg ( 0, std::ios::end );
  size_temp_buffer = file.tellg(  );
  file.seekg ( 0, std::ios::beg );
  temp_buffer = new char[size_temp_buffer];
  file.read ( temp_buffer, size_temp_buffer );
  file.close(  );

  temp_buffer[size_temp_buffer] = '\0';

  std::string pr0 = temp_buffer;

  delete[] temp_buffer;

  return pr0;
}


corex::tools::FileHandler corex::tools::load_binary_file( std::string _path ){
  FILE *file;
  char *buffer;
  unsigned long fileLen;

  //Open file
  file = fopen(_path.c_str(), "rb");

  //Get file length
  fseek(file, 0, SEEK_END);
  fileLen=ftell(file);
  fseek(file, 0, SEEK_SET);

  //Allocate memory
  buffer=(char *)malloc(fileLen+1);
  if (!buffer){
    fprintf(stderr, "Memory error!");
    fclose(file);
  }

  //Read file contents into buffer
  fread(buffer, fileLen, 1, file);
  fclose(file);

  //Do what ever with buffer
  corex::tools::FileHandler handler;
  handler.ptr_memoryblock_ = buffer;
  handler.size_memoryblock_ = fileLen;

  return handler;
}

void corex::tools::save_file( const std::string _path,char* _ptr_buffer ){
  FILE* file_out = fopen( _path.c_str(  ),"wb" );
  fwrite( _ptr_buffer, strlen( _ptr_buffer ),1,file_out );
  fclose( file_out );
}

void corex::tools::save_file( const std::string _path,char* _ptr_buffer ,unsigned int _size ){
  FILE* file_out = fopen( _path.c_str(  ),"wb" );
  fwrite( _ptr_buffer, _size,1,file_out );
  fclose( file_out );
}
