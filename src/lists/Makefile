PROG=list.out
CC=g++
RM=rm -f
CPPFLAGS=-std=c++11 -c -g -Wall

SRCS=singly-linked-list.cc 
OBJS=$(subst .cc,.o,$(SRCS))

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

singly-linked-list.o: singly-linked-list.cc

clean: 
	$(RM) $(OBJS) $(PROG)
