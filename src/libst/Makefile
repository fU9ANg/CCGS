LIB=libst.a
OBJC=STnotification.o SThash.o
CFLAGS=-Wall -g -fPIC
CC=cc


${LIB}:${OBJC}
	ar -crs ${LIB} ${OBJC}
.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJC} ${LIB}
