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

#ifndef _ROUTER_HPP_
#define _ROUTER_HPP_

#include <map>
#include <mutex>
#include <functional>

#include "route.hpp"
#include "request.hpp"
#include "response.hpp"

// Debug mode!.
#define _ROUTER_DEBUG

namespace corex{ namespace web{

class Router{
    std::mutex mfunc;
    std::map< const std::string,std::function<void(corex::web::Request&,corex::web::Response&)> > routes_;
    std::function<void(corex::web::Request&,corex::web::Response&)> not_found_callback_;
    std::vector<corex::web::Route> public_folders_;
    bool is_public_folder;
  public:
    Router(  );
    virtual ~Router(  );
    void push( corex::web::Route,std::function<void(corex::web::Request&,corex::web::Response&)> );
    void push( const std::string,std::function<void(corex::web::Request&,corex::web::Response&)> );
    void push_folder( const corex::web::Route& );
    void del( corex::web::Route );
    void del( std::string );
    void not_found( std::function<void(corex::web::Request&,corex::web::Response&)> );
    void process( corex::web::Request&,corex::web::Response& );
    void execute_callback( const std::string );
};

} }


#endif
