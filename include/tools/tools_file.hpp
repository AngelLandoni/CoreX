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

#ifndef TOOLS_FILE_HPP
#define TOOLS_FILE_HPP

#include <iostream>
#include <fstream>
#ifndef __linux
  #include <cstring>
#endif

#include "error_functions.hpp"

namespace corex{ namespace tools{

struct FileHandler{
  char * ptr_memoryblock_;
  unsigned int size_memoryblock_;
};

std::string b_load_file( std::string& );
FileHandler load_binary_file( std::string );
void save_file( const std::string,char* );
void save_file( const std::string,char*,unsigned int );

} }

#endif
