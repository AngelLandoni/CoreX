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

#ifndef JAVASCRIPT_HPP
#define JAVASCRIPT_HPP

#include <iostream>
#include "../tools/tools_file.hpp"

namespace corex{ namespace web{

class Javascript{
  std::string path_file_;
  char* memblock_;
  unsigned int memblock_size_;
  bool is_load_file;
public:
  Javascript(  );
  Javascript( std::string& );
  Javascript( std::string );
  ~Javascript(  );
  void load_file( std::string& );
  unsigned int get_size_memblock(  );
  std::string get_memblock(  );
};

} }

#endif
