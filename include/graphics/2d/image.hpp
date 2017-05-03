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

#ifndef GRAPHICS_2D_IMAGE_HPP
#define GRAPHICS_2D_IMAGE_HPP

#include <iostream>
#include "../../tools/tools_file.hpp"
#include "../../tools/tools_string.hpp"

enum{
  IMAGE_JPG,
  IMAGE_PNG,
  IMAGE_BMP
};

namespace corex{ namespace graphics{

class Image{
    std::string path_file_;
    char * memblock_; // Contain the data of the image
    unsigned int type_,size_memblock_;
  public:
    Image(  );
    Image( std::string,unsigned int );
    ~Image(  );
    void load( std::string,unsigned char );
    const unsigned char get_type(  );
    char* get_memblock(  );
    unsigned int get_size_memblock(  );
    void set_memblock( const char* );
};

} }


#endif
