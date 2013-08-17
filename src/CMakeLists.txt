
# makefile for cmake

cmake_minimum_required (VERSION 2.8)
project (ccgs)

# options for compiler
SET (CMAKE_CXX_FLAGS_DEBUG " -O0 -Wall -g -ggdb")
SET (CMAKE_C_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb")
# is debug?

SET (CMAKE_BUILD_TYPE Debug )

# which c plus plus compiler
#SET (CMAKE_CXX_COMPILER "clang") # apple clang compiler
SET (CMAKE_CXX_COMPILER "ccache")
SET (CMAKE_CXX_COMPILER_ARG1 "g++")

# which c compiler
#SET (CMAKE_C_COMPILER "clang")   # apple clang compiler
SET (CMAKE_C_COMPILER "ccache")
SET (CMAKE_C_COMPILER_ARG1 "gcc")

# directory for includes
INCLUDE_DIRECTORIES (
    ./
    ./content
    ./includes
)

# source code list
SET (SRC_LIST
    ccgs.cpp
    ccgs_configure.cpp
    ccgs_event_loop.cpp
    ccgs_recv_task.cpp
    ccgs_singleton.cpp
    ccgs_db_connection.cpp
    ccgs_manager.cpp
    ccgs_send_task.cpp
    ccgs_thread_pool.cpp
    ccgs_utils.c
)

# libraries for linker
SET (EXTRA_LIBS 
    -lpthread -lrt -lev -lglog -lmysqlcppconn -llua5.2 -lmemcached
)

# how to compiling programs
add_executable (ccgs ${SRC_LIST})
target_link_libraries (ccgs ${EXTRA_LIBS})
