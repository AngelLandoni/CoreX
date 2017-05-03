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

#include "../../include/tools/concurrent_queue.hpp"

template<typename T>
corex::tools::CQueue<T>::CQueue(  ){
  item_counter = 0;
}

template<typename T>
corex::tools::CQueue<T>::~CQueue(  ){

}

template<typename T>
void corex::tools::CQueue<T>::push( T _item ){
  std::unique_lock<std::mutex> mlock( access_control );
  lifo.push( _item );
  item_counter++;
  mlock.unlock(  );
  condition.notify_one(  );
}

template<typename T>
T corex::tools::CQueue<T>::pop(  ){
  std::unique_lock<std::mutex> mlock( access_control );
  while ( lifo.empty(  ) )
    condition.wait( mlock );
  T item = lifo.front(  );
  lifo.pop(  );
  item_counter--;
  mlock.unlock(  );
  return item;
}

template<typename T>
T* corex::tools::CQueue<T>::ptr_front(  ){
  std::unique_lock<std::mutex> mlock( access_control );
  while ( lifo.empty(  ) )
    condition.wait( mlock );
  T& item = lifo.front(  );
  mlock.unlock(  );
  return item;
}

template<typename T>
bool corex::tools::CQueue<T>::is_empty(  ){
  if( item_counter == 0 ) return true;
  return false;
}
