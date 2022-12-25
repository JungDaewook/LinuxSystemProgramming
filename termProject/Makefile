CC = gcc
CFLAGS =
LDFLAGS = -lnsl -lpthread

.SUFFIXES : .c .o
.c.o :
	$(CC) -c $(CFLAGS) $<

ALL = chats chatc chatcMultiThreads chatsMultiPlexing

all: $(ALL)

chats: chats.o 
	$(CC) -o $@ $< $(LDFLAGS)

chatc: chatc.o 
	$(CC) -o $@ $< $(LDFLAGS)

chatcMultiThreads: chatcMultiThreads.o 
	$(CC) -o $@ $< $(LDFLAGS)

chatsMultiPlexing: chatsMultiPlexing.o 
	$(CC) -o $@ $< $(LDFLAGS)

clean :
	rm -rf *.o $(ALL)
