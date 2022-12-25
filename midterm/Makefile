CC = gcc
CFLAGS =
LDFLAGS = -pthread -lpthread

.SUFFIXES : .c .o
.c.o :
	$(CC) -c $(CFLAGS) $<

ALL = mycp hole list tcp1 tcp2 mycp2 split merge conv access tab

all: $(ALL)

clean :
	rm -rf *.o $(ALL) file.hole
