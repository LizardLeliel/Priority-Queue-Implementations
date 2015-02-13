CC = gcc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.cpp=.o)
PROG = heaps

CFLAGS = -O2 -Wall -Wextra -pg -std=c99  

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
	rm -f *.bak vecmath/src/*.o *.o core.* $(PROG) 