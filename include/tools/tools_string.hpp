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

#ifndef TOOLS_STRING_HPP
#define TOOLS_STRING_HPP

#include <iostream>
#include <vector>
#include <map>

#define JUMPLINE '\n'

namespace corex{ namespace tools{

void show_s( std::string _buffer );
std::string string_get_first_line( std::string );
std::vector<std::string> string_split( std::string,char );
std::vector<std::string> string_split_first( std::string,char );
std::string string_to_lower( std::string );
void string_replace( std::string&,char,char );
unsigned int string_count_char( std::string&,char );
void string_delete_char( std::string&,char );
void string_delete_section( std::string&,unsigned int,unsigned int );
void string_inyect_buffer( std::string&,std::string&,unsigned int ); // Inyect a string in to string
unsigned int string_find( const std::string&,char );
std::map<std::string,std::string> string_vector_to_map( std::vector<std::string>& );

} }

#endif
