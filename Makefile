CC = g++
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
PROG = priorityQueue

CFLAGS = -O2 -Wall  -pg -std=gnu++11 

# Unused variables is turned off while program is being written
# (the warnings get anonying, especially since they will be used eventually)
# I got to remember to turn it back on later, though @_@
CFLAGS += -Wno-unused-parameter -Wno-unused-variable  

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LINKFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(INCFLAGS)

clean:
	rm -f *.bak  *.o core.* $(PROG) 