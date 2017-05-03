#
# Copyright (C) 2014-2015 Landoni Angel <angelland28@gmail.com>
#
# CoreX is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# CoreX is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program.  If not, see <http://www.gnu.org/licenses/>.
#

CC = clang++
CFLAGS = -std=c++11
COPTIONS = -c -o

EXECNAME = corex

BINRELEASEDIR = bin/
OBJDIR = obj/

INCLUDEDIR = include/
INCLUDEDIR_WEB = include/web/
INCLUDEDIR_TOOLS = include/tools/
INCLUDEDIR_NET = include/net/
INCLUDEDIR_DATABASE = include/database/
INCLUDEDIR_GRAPHICS_2D = include/graphics/2d/

SRCDIR = src/
SRCDIR_WEB = src/web/
SRCDIR_TOOLS = src/tools/
SRCDIR_NET = src/net/
SRCDIR_DATABASE = src/database/
SRCDIR_GRAPHICS_2D = src/graphics/2d/

OBJ = main.o corex.o tools_error.o tools_error_functions.o tools_string.o tools_file.o tools_concurrent_queue.o tools_dynamic_memory.o tools_thread_pool.o graphics_2d_image.o net_socket_server_client_handler.o net_socket_server.o net_tcp_client.o web_request.o web_response.o web_server.o web_css.o web_html.o web_javascript.o web_route.o web_router.o database_redis_client.o
OBJINDIR = obj/*.o

corex: $(OBJ)
	$(CC) $(CFLAGS) $(OBJINDIR) -o $(BINRELEASEDIR)$(EXECNAME)

# THE MAIN FILE!
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(COPTIONS) $(OBJDIR)main.o

# COREX LIBRARY
corex.o: $(SRCDIR)corex.cpp $(INCLUDEDIR)corex.hpp
	$(CC) $(CFLAGS) $(SRCDIR)corex.cpp $(COPTIONS) $(OBJDIR)corex.o

# ============================= TOOLS ===============================

#[ERROR.HPP]
tools_error.o: $(SRCDIR_TOOLS)error.cpp $(INCLUDEDIR_TOOLS)error.hpp
	$(CC) $(CFLAGS) $(SRCDIR_TOOLS)error.cpp $(COPTIONS) $(OBJDIR)tools_error.o

#[ERROR_FUNCTIONS.HPP]
tools_error_functions.o: $(SRCDIR_TOOLS)error_functions.cpp $(INCLUDEDIR_TOOLS)error_functions.hpp
	$(CC) $(CFLAGS) $(SRCDIR_TOOLS)error_functions.cpp $(COPTIONS) $(OBJDIR)tools_error_functions.o

#[TOOLS_STRING.HPP]
tools_string.o: $(SRCDIR_TOOLS)tools_string.cpp $(INCLUDEDIR_TOOLS)tools_string.hpp
	$(CC) $(CFLAGS) $(SRCDIR_TOOLS)tools_string.cpp $(COPTIONS) $(OBJDIR)tools_string.o

#[TOOLS_FILE.HPP]
tools_file.o: $(SRCDIR_TOOLS)tools_file.cpp $(INCLUDEDIR_TOOLS)tools_file.hpp
	$(CC) $(CFLAGS) $(SRCDIR_TOOLS)tools_file.cpp $(COPTIONS) $(OBJDIR)tools_file.o

#[CONCURRENT_QUEUE.HPP]
tools_concurrent_queue.o: $(SRCDIR_TOOLS)concurrent_queue.cpp $(INCLUDEDIR_TOOLS)concurrent_queue.hpp
	$(CC) $(CFLAGS) $(SRCDIR_TOOLS)concurrent_queue.cpp $(COPTIONS) $(OBJDIR)tools_concurrent_queue.o

#[DYNAMIC_MEMORY.HPP]
tools_dynamic_memory.o: $(SRCDIR_TOOLS)dynamic_memory.cpp $(INCLUDEDIR_TOOLS)dynamic_memory.hpp
		$(CC) $(CFLAGS) $(SRCDIR_TOOLS)dynamic_memory.cpp $(COPTIONS) $(OBJDIR)tools_dynamic_memory.o

#[THREAD_POOL.HPP]
tools_thread_pool.o: $(SRCDIR_TOOLS)thread_pool.cpp $(INCLUDEDIR_TOOLS)thread_pool.hpp
		$(CC) $(CFLAGS) $(SRCDIR_TOOLS)thread_pool.cpp $(COPTIONS) $(OBJDIR)tools_thread_pool.o


# ===================================================================

# =========================== GRAPHICS ==============================

# =========================== 2D

#[SERVER_SOCKET.HPP]
graphics_2d_image.o: $(SRCDIR_GRAPHICS_2D)image.cpp $(INCLUDEDIR_GRAPHICS_2D)image.hpp
	$(CC) $(CFLAGS) $(SRCDIR_GRAPHICS_2D)image.cpp $(COPTIONS) $(OBJDIR)graphics_2d_image.o

# ==============================

# ===================================================================


# ============================== NET ================================

#[SERVER_SOCKET_CLIENTE_HANDLER.HPP]
net_socket_server_client_handler.o: $(SRCDIR_NET)socket_server_client_handler.cpp $(INCLUDEDIR_NET)socket_server_client_handler.hpp
	$(CC) $(CFLAGS) $(SRCDIR_NET)socket_server_client_handler.cpp $(COPTIONS) $(OBJDIR)net_socket_server_client_handler.o

#[SERVER_SOCKET.HPP]
net_socket_server.o: $(SRCDIR_NET)socket_server.cpp $(INCLUDEDIR_NET)socket_server.hpp
	$(CC) $(CFLAGS) $(SRCDIR_NET)socket_server.cpp $(COPTIONS) $(OBJDIR)net_socket_server.o

#[TCP_CLIENT.HPP]
net_tcp_client.o: $(SRCDIR_NET)tcp_client.cpp $(INCLUDEDIR_NET)tcp_client.hpp
	$(CC) $(CFLAGS) $(SRCDIR_NET)tcp_client.cpp $(COPTIONS) $(OBJDIR)net_tcp_client.o

# ===================================================================


# ============================== WEB ================================

#[CSS.HPP]
web_css.o: $(SRCDIR_WEB)css.cpp $(INCLUDEDIR_WEB)css.hpp
	$(CC) $(CFLAGS) $(SRCDIR_WEB)css.cpp $(COPTIONS) $(OBJDIR)web_css.o

#[HTML.HPP]
web_html.o: $(SRCDIR_WEB)html.cpp $(INCLUDEDIR_WEB)html.hpp
	$(CC) $(CFLAGS) $(SRCDIR_WEB)html.cpp $(COPTIONS) $(OBJDIR)web_html.o

#[JAVASCRIPT.HPP]
web_javascript.o: $(SRCDIR_WEB)javascript.cpp $(INCLUDEDIR_WEB)javascript.hpp
	$(CC) $(CFLAGS) $(SRCDIR_WEB)javascript.cpp $(COPTIONS) $(OBJDIR)web_javascript.o

#[REQUEST.HPP]
web_request.o: $(SRCDIR_WEB)request.cpp $(INCLUDEDIR_WEB)request.hpp
	$(CC) $(CFLAGS) $(SRCDIR_WEB)request.cpp $(COPTIONS) $(OBJDIR)web_request.o

#[RESPONSE.HPP]
web_response.o: $(SRCDIR_WEB)response.cpp $(INCLUDEDIR_WEB)response.hpp
	$(CC) $(CFLAGS) $(SRCDIR_WEB)response.cpp $(COPTIONS) $(OBJDIR)web_response.o

#[WEB_SERVER.HPP]
web_server.o: $(SRCDIR_WEB)web_server.cpp $(INCLUDEDIR_WEB)web_server.hpp
	$(CC) $(CFLAGS) $(SRCDIR_WEB)web_server.cpp $(COPTIONS) $(OBJDIR)web_server.o

#[ROUTE.HPP]
web_route.o: $(SRCDIR_WEB)route.cpp $(INCLUDEDIR_WEB)route.hpp
	$(CC) $(CFLAGS) $(SRCDIR_WEB)route.cpp $(COPTIONS) $(OBJDIR)web_route.o


#[ROUTER.HPP]
web_router.o: $(SRCDIR_WEB)router.cpp $(INCLUDEDIR_WEB)router.hpp
	$(CC) $(CFLAGS) $(SRCDIR_WEB)router.cpp $(COPTIONS) $(OBJDIR)web_router.o


# ==================================================================

# =========================== DATABASE =============================

#[REDIS_CLIENT.HPP]
database_redis_client.o: $(SRCDIR_DATABASE)redis_client.cpp $(INCLUDEDIR_DATABASE)redis_client.hpp
	$(CC) $(CFLAGS) $(SRCDIR_DATABASE)redis_client.cpp $(COPTIONS) $(OBJDIR)database_redis_client.o

# ==================================================================
