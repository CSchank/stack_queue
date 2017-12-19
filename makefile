CFLAGS = -Wall -g -ansi -O2 -std=c99

all : stack queue

stack: main_stack.o stack.o
	$(CC) -o $@ main_stack.o stack.o

queue: main_queue.o queue.o
	$(CC) -o $@ main_queue.o queue.o

c: clean

clean:
	rm -rf stack queue *.o *~ 