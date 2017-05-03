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

#include "../../../include/graphics/2d/image.hpp"

corex::graphics::Image::Image(  ){

}

corex::graphics::Image::Image( std::string _path, unsigned int _type ){
  path_file_ = _path;
  type_ = _type;

  corex::tools::FileHandler memhandler = corex::tools::load_binary_file( _path );

  memblock_ = memhandler.ptr_memoryblock_;
  size_memblock_ = memhandler.size_memoryblock_;
}

corex::graphics::Image::~Image(  ){
  delete[] memblock_;
}

void corex::graphics::Image::load( std::string _path,unsigned char _type ){
  path_file_ = _path;
  type_ = _type;
  corex::tools::FileHandler memhandler = corex::tools::load_binary_file( _path );

  memblock_ = memhandler.ptr_memoryblock_;
  size_memblock_ = memhandler.size_memoryblock_;
}

const unsigned char corex::graphics::Image::get_type(  ){
  return type_;
}

char * corex::graphics::Image::get_memblock(  ){
  return memblock_;
}

unsigned int corex::graphics::Image::get_size_memblock(  ){
  return size_memblock_;
}

void corex::graphics::Image::set_memblock( const char * _ptr_buffer ){
  delete[] memblock_;
  size_memblock_ = sizeof(_ptr_buffer)/sizeof(char);
  memblock_ = new char[size_memblock_];
  strcpy( memblock_,_ptr_buffer );
}
