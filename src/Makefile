
#
# makefile
#

# set src, dst directory and flags for protobuf
PROTOC  = protoc
PBFLAGS = --cpp_out
PBSRC   = ./protos
PBDST   = ./message

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
#-D_OLD_MAKEHOUSE_GAME

# objects
OBJS    = 	ccgs.o \
			ccgs_configure.o \
			ccgs_event_loop.o  \
			ccgs_recv_task.o  \
			ccgs_singleton.o \
			ccgs_db_connection.o \
			ccgs_manager.o \
			ccgs_send_task.o \
			ccgs_thread_pool.o \
			ccgs_utils.o \
			ccgs_memcached.o \
			ccgs_module.o


# binary
BIN	    = ccgs

# where are include files kept
INC	    = -I. -I./includes -I./message -I./libst -I./module

# for Linker
#LINK        = libs/libev.a libs/libglog.a libs/liblua52.so libs/libmysqlcppconn.so libs/libmemcached.so
LINK        = -lev -lglog -lmysqlcppconn -llua5.2 -lmemcached -lprotobuf -lpthread \
              -lboost_system -lboost_thread -lboost_program_options -lboost_filesystem -lrt \
              libst/libst.a
# rock..

all: clean libst.a precompile_protobuf $(BIN)

libst.a:
	cd libst && make
# pre-compile protobuf
precompile_protobuf:
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/*

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
	-rm -rf $(OBJS) $(BIN) *~ logs .lock message/*
	cd ./libst/ && make clean
