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

void corex::web::compress( corex::web::Html& _ref_html ){
  std::string buffer = _ref_hmtl.get_memblock(  ),
              temp_buffer = "";
  unsigned int buffer_length = buffer.length(  ),
               i = 0;
  while( i<buffer_length ){
    if( buffer[i] != COMPRESSOR_HTML_TOKEN_JUMPLINE )
      temp_buffer += buffer[i];
    i++;
  }
  _ref_html.set_content( _ref_html );
}

void corex::web::compress( corex::web::Css& _ref_css ){

}

void corex::web::compress( corex::web::Javascript& ){

}
