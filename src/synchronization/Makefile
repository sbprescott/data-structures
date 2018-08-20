PROG=sync
CC=g++
RM=rm -f
CPPFLAGS=-std=c++11 -c -g -Wall

SRCS=binary_semaphore.cc readers_writers.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -pthread -o $(PROG) $(OBJS)

binary_semaphore.o: binary_semaphore.cc

readers_writers.o: readers_writers.cc

clean: 
	$(RM) $(OBJS) $(PROG)
