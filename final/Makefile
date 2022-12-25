CC = gcc
CFLAGS =
LDFLAGS = -lpthread

.SUFFIXES : .c .o
.c.o :
	$(CC) -c $(CFLAGS) $<

ALL = rpc app

all: $(ALL)

rpc: rpc.o semlib.o
	$(CC) -o $@ $^ $(LDFLAGS)
app: app.o semlib.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean :
	rm -rf *.o $(ALL)
