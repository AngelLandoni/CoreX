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

#ifndef _COMPRESSOR_HPP_
#define _COMPRESSOR_HPP_

#include "html.hpp"
#include "css.hpp"
#include "javascript.hpp"

#define COMPRESSOR_HTML_TOKEN_JUMPLINE '\n'

namespace corex{ namespace web{

void compress( corex::web::Html& );
void compress( corex::web::Css& );
void compress( corex::web::Javascript& );

} }

#endif
