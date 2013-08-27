
#
# makefile
#

# set src, dst directory and flags for protobuf
PROTOC  = protoc
PBFLAGS = --cpp_out
PBSRC   = ./protos
PBDST   = ./message

# which c plus plus compiler
CPP     = ccache c++

# which c compiler
CC      = ccache cc

# options for compiler
CFLAGS  = -Wall -Werror -fPIC

# is debug? (for development)
CDEBUG  = -g

# macro
CMACRO	= 
#-D_OLD_MAKEHOUSE_GAME

# objects
OBJS    =		ccgs_module.o \
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
			ccgs_common.o


# binary
BIN	    = ccgs

# CCGS library for developer
LIBCCGS     = libccgs.so
# where are include files kept
INC	    = -I. -I./includes -I./message -I/usr/local/include 

# for Linker
#LINK        = libs/libev.a libs/libglog.a libs/liblua52.so libs/libmysqlcppconn.so libs/libmemcached.so
LINK        = -L/usr/local/lib -lev -lglog -lmysqlcppconn -llua-5.2 -lmemcached -lprotobuf -lpthread \
              -lboost_system -lboost_thread -lboost_program_options -lboost_filesystem -lrt
# rock..

all: clean libst.a precompile_protobuf ${LIBCCGS} $(BIN)

libst.a:
	cd libst && make
# pre-compile protobuf
precompile_protobuf:
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/*

# build CCGS shared library.
${LIBCCGS}: ${OBJS}
	${CC} ${OBJS} -shared -fPIC -o ${LIBCCGS} $(LINK) libst/libst.a
# how to compiling programs
#$(BIN):$(OBJS)
$(BIN):$(LIBCCGS)
#	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(OBJS)
#	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) -o $@ $(OBJS) $(LIBA) $(LINK)
	${CPP} -L./ -lccgs ccgs.cpp -o $(BIN) $(INC)
%.o:%.cpp
	echo "$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<"
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf *.o $(BIN) *~ logs .lock message/* ${LIBCCGS}
	cd ./libst/ && make clean
