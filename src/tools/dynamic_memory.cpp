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

#include "../../include/tools/dynamic_memory.hpp"

corex::tools::DynamicMemory::DynamicMemory(  ){
  memory_ = ( char * )malloc( DYNAMICMEMORY_SIZE_MEMORY*sizeof( char ) );
  std::memset( memory_,'\0',DYNAMICMEMORY_SIZE_MEMORY );
  last_char_pos_ = 0;
  size_memory_ = DYNAMICMEMORY_SIZE_MEMORY;
}

corex::tools::DynamicMemory::~DynamicMemory(  ){
  delete[] memory_;
}

void corex::tools::DynamicMemory::push( char _token ){
  if( size_memory_-last_char_pos_ < 1 ){
    memory_ = ( char* )realloc( memory_, size_memory_*DYNAMICMEMORY_SCALE_CONSTANT );
    size_memory_ *= DYNAMICMEMORY_SCALE_CONSTANT;
  }
  memory_[last_char_pos_] = _token;
  last_char_pos_++;
}

void corex::tools::DynamicMemory::push( char* _ptr_buffer ){
  unsigned int size_buffer = strlen( _ptr_buffer );
  if( size_memory_-last_char_pos_ < size_buffer ){
    memory_ = ( char* )realloc( memory_, size_memory_*DYNAMICMEMORY_SCALE_CONSTANT );
    size_memory_ *= DYNAMICMEMORY_SCALE_CONSTANT;
  }
  last_char_pos_ += size_buffer;
  strcat( memory_,_ptr_buffer );
}

void corex::tools::DynamicMemory::push( char* _ptr_buffer,unsigned int _size ){
  // MEJOR OPTIMIZACION!?
  unsigned int i = 0;
  for( i=0;i<_size;i++ )
    push( _ptr_buffer[i] );
}

void corex::tools::DynamicMemory::push( const char * _ptr_buffer ){
  unsigned int size_buffer = strlen( _ptr_buffer );
  if( size_memory_-last_char_pos_ < size_buffer ){
    memory_ = ( char* )realloc( memory_, size_memory_*DYNAMICMEMORY_SCALE_CONSTANT );
    size_memory_ *= DYNAMICMEMORY_SCALE_CONSTANT;
  }
  last_char_pos_ += size_buffer;
  strcat( memory_,_ptr_buffer );
}

char * corex::tools::DynamicMemory::get(  ){
  return memory_;
}

unsigned int corex::tools::DynamicMemory::get_size(  ){
  return size_memory_;
}

unsigned int corex::tools::DynamicMemory::get_buffer_size(  ){
  // ????????????????????? why -1?
  // SOLVE THIS!
  return last_char_pos_-1;
}
