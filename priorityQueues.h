#ifndef PRIORITY_QUEUE_FLAVOURS

#include <stdbool.h>

struct Node;

// We need to use void pointers because the structure of the heap/queue
//  nodes changes depending on implementation
void insert(struct Node** implementation, int newNum);

int pop(struct Node** implementation);


void runHeapTest(int elements, int dump, bool printOutput);


#define PRIORITY_QUEUE_FLAVOURS
#endif