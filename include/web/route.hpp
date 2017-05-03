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

#ifndef _ROUTE_HPP_
#define _ROUTE_HPP_

#include <iostream>
#include <vector>

#define ROUTE_TOKE_TO_PARSE '/'

namespace corex{ namespace web{

class Route{
    std::string buffer_;  // the route string
    std::vector<std::string> parse_buffer_;
  public:
    Route(  );
    Route( const std::string );
    virtual ~Route(  );
    void operator()( const std::string );
    void operator=( const std::string );
    void operator=( corex::web::Route& );
    void set( const std::string );
    std::string get(  );
};

} }


#endif
