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

#include "../../include/tools/error.hpp"

corex::tools::Error::Error(  ){
  state = true;
  message =  "";
  id = 0;
}

corex::tools::Error::Error( unsigned int _id,std::string _message ){
  state = true;
  id = _id;
  message = _message;
}

corex::tools::Error::~Error(  ){

}

void corex::tools::Error::set( unsigned int _id,std::string _message ){
  if( !state ) return;
  id = _id;
  message = _message;
}

void corex::tools::Error::set_id( unsigned int _id ){
  if( !state ) return;
  id = _id;
}

void corex::tools::Error::set_message( std::string _message ){
  if( !state ) return;
  message = _message;
}

void corex::tools::Error::set_state( bool _value ){
  state = _value;
}

unsigned int corex::tools::Error::get_id(  ){
  return id;
}

std::string corex::tools::Error::get_message(  ){
  return message;
}
