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

#ifndef COREX_HPP
#define COREX_HPP

#include "tools/tools_string.hpp"
#include "tools/error.hpp"
#include "net/socket_server.hpp"
#include "net/tcp_client.hpp"
#include "web/web_server.hpp"
#include "web/router.hpp"
#include "database/redis_client.hpp"
#include "graphics/2d/image.hpp"

#define VERSION_COREX "0.2";
#define BUILD_NUMBER 1;

namespace corex{

typedef std::map<std::string,std::string> KeyValue;

std::string get_version(  );
std::string get_info(  );

}


#endif
