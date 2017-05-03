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

#ifndef HTML_HPP
#define HTML_HPP

#include <fstream>
#include <map>

#include "../tools/tools_file.hpp"
#include "../tools/error_functions.hpp"

//[HELPERS]
#define END_OF_LINE '\0'
#define MAPING_TOKEN_BEGIN '['
#define MAPING_TOKEN_END ']'

typedef std::map<std::string,std::string> HtmlMap;

namespace corex{ namespace web{

class Html{
  std::string path_file_;
  char* memblock;
  unsigned int memblock_size;
  bool is_file_load;
public:
  Html(  );
  Html( std::string );
  Html( std::string,std::map<std::string,std::string>& );
  ~Html(  );
  void load_file( std::string& );
  void load_file( std::string&,std::map<std::string,std::string>& );
  void set_content( const std::string );
  void set_content( const std::string& );
  void maping( std::map<std::string,std::string>& );
  unsigned int get_size_memblock(  );
  std::string get_memblock(  );

};


} }


#endif
