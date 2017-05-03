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

#ifndef CONCURRENT_QUEUE_HPP
#define CONCURRENT_QUEUE_HPP

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "../net/socket_server_client_handler.hpp"

namespace corex{ namespace tools{

template<typename T>
class CQueue{
  std::queue<T> lifo;
  std::mutex access_control;
  std::condition_variable condition;
  int item_counter;
public:
  CQueue(  );
  virtual ~CQueue(  );
  void push( T );
  T pop(  );
  T* ptr_front(  );
  bool is_empty(  );
};

} }

#endif
