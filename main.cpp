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

#include <iostream>
#include <vector>

#include "include/corex.hpp"

int main(  ){
  corex::web::Router app_router;

  app_router.push( corex::web::Route( "/" ),
  [ & ]( corex::web::Request& req,corex::web::Response& res ){
    corex::web::Html thtml( "tests/index" );
    res.send( thtml );
  } );

  app_router.push( corex::web::Route( "/toduckduckgo" ),
  []( corex::web::Request& req,corex::web::Response& res ){
    res.redirect( "http://www.duckduckgo.com/" );
  } );

  app_router.push( corex::web::Route( "/getitems" ),
  []( corex::web::Request& req,corex::web::Response& res ){
    corex::KeyValue mapping;
    mapping["name"] = req.get_var( "fname" );
    mapping["surname"] = req.get_var( "lname" );

    corex::web::Html templateHtml( "tests/datos",mapping );
    res.send( templateHtml );
  } );

  app_router.push( "/style",
  [ & ]( corex::web::Request& req,corex::web::Response& res ){
    corex::web::Css tcss( "tests/style" );
    res.send( tcss );
  } );

  app_router.push( "/img",
  [ & ]( corex::web::Request& req,corex::web::Response& res ){
    corex::graphics::Image img( "tests/img.jpg",IMAGE_JPG );
    res.send( img );
  } );

  app_router.not_found( []( corex::web::Request& req,corex::web::Response& res ){
    corex::KeyValue tabledata;
    tabledata["web_search"] = req.get( "url" );
    corex::web::Html error_no_found_web( "tests/not_found",tabledata );
    res.send( error_no_found_web );
  } );

  corex::web::WebServer app( 1333,16 );
  app.run( app_router );

  return 0;
}
