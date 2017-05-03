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

#include "../../include/web/route.hpp"

corex::web::Route::Route(  ){

}

corex::web::Route::Route( const std::string _route ){
  buffer_ = _route;
}

corex::web::Route::~Route(  ){

}

void corex::web::Route::operator()( const std::string _route ){
  buffer_ = _route;
}

void corex::web::Route::operator=( const std::string _route ){
  buffer_ = _route;
}

void corex::web::Route::operator=( corex::web::Route& _ref_route ){
  buffer_ = _ref_route.get(  );
  /*
    Parse buffer and bla bla bla
  */
}

void corex::web::Route::set( const std::string _const_route ){
  buffer_ = _const_route;
}

std::string corex::web::Route::get(  ){
  return buffer_;
}
