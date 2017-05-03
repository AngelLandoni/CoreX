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

#ifndef DYNAMIC_MEMORY_HPP
#define DYNAMIC_MEMORY_HPP

#include <iostream>
#ifndef __linux
  #include <cstring>
#endif


#define DYNAMICMEMORY_SIZE_MEMORY 5000
#define DYNAMICMEMORY_SCALE_CONSTANT 2

namespace corex{ namespace tools{

class DynamicMemory{
    char * memory_;
    unsigned int size_memory_,
                   last_char_pos_;
  public:
    DynamicMemory(  );
    ~DynamicMemory(  );
    void push( char );
    void push( char* );
    void push( char*,unsigned int );
    void push( const char* );
    char * get(  );
    unsigned int get_size(  );
    unsigned int get_buffer_size(  );
};

} }

#endif
