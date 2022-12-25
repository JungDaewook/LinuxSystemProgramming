CC = gcc
CFLAGS =
LDFLAGS = -lpthread

.SUFFIXES : .c .o
.c.o :
	$(CC) -c $(CFLAGS) $<

ALL = show tadd

all: $(ALL)


show: show.o
	$(CC) -o $@ $< $(LDFLAGS)

tadd: tadd.o
	$(CC) -o $@ $< $(LDFLAGS)

clean :
	rm -rf *.o $(ALL)
