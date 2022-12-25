CC = gcc
GFLAGS = 
LDFLAGS = -L. -lmine
TARGET = bug
OBJS = bug.o

.SURFIXES : .c .o
.c.o :
	$(CC) -c $(CFLAGS) $<

$(TARGET) : $(OBJS) libmine.a
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

libmine.a : mystrcpy.o
	ar ruv libmine.a mystrcpy.o

clean :
	rm -rf libmine.a $(TARGET) *.o
