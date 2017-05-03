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

#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>

namespace corex{ namespace tools{

class Error{
  unsigned int id;
  std::string message;
  bool state;
public:
  Error(  );
  Error( unsigned int,std::string );
  virtual ~Error(  );
  void set( unsigned int,std::string );
  void set_id( unsigned int );
  void set_message( std::string );
  void set_state( bool );
  unsigned int get_id(  );
  std::string get_message(  );
};

} }

#endif
