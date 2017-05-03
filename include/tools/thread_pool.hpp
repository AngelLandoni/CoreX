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

#ifndef _THREAD_POOL_HPP_
#define _THREAD_POOL_HPP_

#include <vector>
#include <thread>

namespace corex{ namespace tools{

class ThreadPool{
    unsigned int num_workers_;
    std::vector<std::thread> workers_;
    void (*ptr_callback_)(  );
  public:
    ThreadPool(  );
    ThreadPool( void(*)(  ),unsigned int );
    virtual ~ThreadPool(  );
    void create( void(*)(  ),unsigned int );
    void join(  );
};

} }


#endif
