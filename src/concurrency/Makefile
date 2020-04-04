CXX=g++
RM=rm -f
CXXFLAGS=-g -Wall -pthread -std=c++11


SRCS=binary_semaphore.cc barrier.cc vector_addition.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: max

max: $(OBJS)
	 $(CXX) $(CXXFLAGS) -o max.out $(OBJS)


binary_semaphore.o: binary_semaphore.cc

barrier.o: barrier.cc 

vector_addition.o: vector_addition.cc

clean:
	$(RM) $(OBJS) max.out
