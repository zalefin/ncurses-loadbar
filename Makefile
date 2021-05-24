CC=gcc
CFLAGS=
LFLAGS=-lncurses

.PHONY: clean

ncloadbar: main.c loadbar.o
	${CC} $^ ${LFLAGS} -o $@

loadbar.o: loadbar.h loadbar.c
	${CC} $^ ${CFLAGS} -c

clean:
	rm -rf *.o *.gch ncloadbar
