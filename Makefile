CXX=g++
CPPFLAGS=-std=c++11
RM=rm -f

SRCS=src/vector/vector.cpp src/vector/vector_test.cpp

OBJS=$(subst .cpp,.o,$(SRCS))

all: vector

vector: $(OBJS)
	$(CXX) $(CPPFLAGS) -o vector.out $(OBJS)

clean:
	$(RM) $(OBJS)