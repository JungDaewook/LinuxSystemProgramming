# I will use gcc for compiler
CC=gcc 
#my compile option is -g(debug) -Wall(warning)
CFLAGS=-g -Wall
#My target file name is a.out
TARGET=a.out
#list of obj files
OBJS=a.o b.o main.o
 
#make target by obj files by below command line
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

#make a.o by a.c by below command line
a.o : a.c
	$(CC) -c -o a.o a.c

#make b.o by b.c by below command line
b.o : b.c
	$(CC) -c -o b.o b.c

#make main.o by main.c by below command line
main.o : main.c
	$(CC) -c -o main.o main.c

#clean make by below command line
clean:
	rm $(OBJECT) $(TARGET)
