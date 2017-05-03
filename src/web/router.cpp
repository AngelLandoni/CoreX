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

#include "../../include/web/router.hpp"

corex::web::Router::Router(  ){
  is_public_folder = false;
}

corex::web::Router::~Router(  ){

}

void corex::web::Router::push( corex::web::Route _route,
                                   std::function<void(corex::web::Request&,corex::web::Response&)> _callback ){
 routes_[ _route.get(  ) ] = _callback;
}

void corex::web::Router::push( const std::string _route,
                                   std::function<void(corex::web::Request&,corex::web::Response&)> _callback ){
 routes_[ _route ] = _callback;
}

void corex::web::Router::push_folder( const corex::web::Route& _ref_route ){
  corex::web::Route temp_route = _ref_route;
  public_folders_.push_back( temp_route );
  is_public_folder = true;
}

void corex::web::Router::del( corex::web::Route _route ){
  routes_.erase( _route.get(  ) );
}

void corex::web::Router::del( const std::string _route ){
  routes_.erase( _route );
}

void
corex::web::Router::not_found(
std::function<void(corex::web::Request&,corex::web::Response&)> _not_found_callback
){
  not_found_callback_ = _not_found_callback;
}

void corex::web::Router::process( corex::web::Request& _ref_req,corex::web::Response& _ref_res ){
  std::string url = _ref_req.get( "url" );
  if ( routes_.find( url ) == routes_.end(  ) ) {
    not_found_callback_( _ref_req,_ref_res );
  }else if( is_public_folder ){

  }else try{
    routes_[ url ]( _ref_req,_ref_res );
  } catch(const std::bad_function_call& e) {
      #ifdef _ROUTER_DEBUG
      corex::tools::show_s( e.what() );
      #endif
  }
}

void corex::web::Router::execute_callback( const std::string _route ){
  std::function<void(corex::web::Request&,corex::web::Response&)> _callback = routes_[ _route ];

  corex::web::Request ccc;
  corex::web::Response aaa;
  _callback( ccc,aaa );
}
