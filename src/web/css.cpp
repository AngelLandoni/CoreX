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

#include "../../include/web/css.hpp"

corex::web::Css::Css(  ){
  is_file_load_ = false;
  memblock_size_ = 0;
}

corex::web::Css::Css( const std::string _ref_path_file ){
  this->load_file( _ref_path_file );
}

corex::web::Css::~Css(  ){

}

void corex::web::Css::load_file( const std::string _ref_path_file ){
  std::string _path = _ref_path_file;
  std::string buffer = corex::tools::b_load_file( _path );
  memblock_size_ = buffer.length(  );
  memblock_ = new char[ memblock_size_ ];
  memset( memblock_,'\0',memblock_size_ );
  strcpy( memblock_,buffer.c_str(  ) );
  is_file_load_ = true;
}

unsigned int corex::web::Css::get_size_memblock(  ){
  return memblock_size_;
}

std::string corex::web::Css::get_memblock(  ){
  if( !is_file_load_ ) return "";
  return memblock_;
}
