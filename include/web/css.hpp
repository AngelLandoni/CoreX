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

#ifndef CSS_HPP
#define CSS_HPP

#include "../tools/tools_file.hpp"

namespace corex{ namespace web{

class Css{
  std::string path_file_;
  char* memblock_;
  unsigned int memblock_size_;
  bool is_file_load_;
public:
  Css(  );
  Css( const std::string );
  ~Css(  );
  void load_file( const std::string );
  unsigned int get_size_memblock(  );
  std::string get_memblock(  );
};

} }

#endif
