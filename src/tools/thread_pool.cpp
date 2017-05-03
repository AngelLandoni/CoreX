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

#include "../../include/tools/thread_pool.hpp"

corex::tools::ThreadPool::ThreadPool(  ){

}

corex::tools::ThreadPool::ThreadPool( void(*_ptr_callback)(  ),unsigned int _num_workers ){
  create( _ptr_callback,_num_workers );
}

corex::tools::ThreadPool::~ThreadPool(  ){

}

void corex::tools::ThreadPool::create( void(*_ptr_callback)(  ),unsigned int _num_workers ){
  unsigned int i = 0;
  num_workers_ = _num_workers;
  ptr_callback_ = _ptr_callback;
  while( i<_num_workers ){
    workers_.push_back( std::thread( [&](){
      ptr_callback_(  );
    } ) );
    i++;
  }
}

void corex::tools::ThreadPool::join(  ){
  unsigned int i = 0;
  while( i<num_workers_ ){
    workers_[i].join(  );
    i++;
  }
}
