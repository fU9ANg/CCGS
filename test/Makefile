
#
# makefile for unit test of CCGS
#

# which c plus plus compiler
CPP     = ccache g++

# which c compiler
CC      = ccache cc

# options for compiler
CFLAGS  = -Wall -Werror

# is debug? (for development)
CDEBUG  = -g

# macro
CMACRO	= 

# objects
OBJS    = 	gtest_main.o \
			utest_arithmetic_expressions.o \
			utest_lib_event.o \
			utest_common_buffer.o \
			utest_configure.o \
			utest_db_connection.o \
			utest_mem_pool.o \
			../src/ccgs_configure.o \
			../src/ccgs_db_connection.o

# binary
BIN	    = unitest

# where are include files kept
INC	    = -I. -I../src/includes -I../src/

# for Linker
#LINK        = libs/libev.a libs/libglog.a libs/liblua52.so libs/libmysqlcppconn.so libs/libmemcached.so
LINK        = -lev -lglog -lmysqlcppconn -llua5.2 -lmemcached -lprotobuf -lpthread \
              -lboost_system -lboost_thread -lboost_program_options -lboost_filesystem -lrt \
			  -lgtest

# how to compiling programs
$(BIN):$(OBJS)
#	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) -o $@ $(OBJS) $(LIBA) $(LINK)
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~
