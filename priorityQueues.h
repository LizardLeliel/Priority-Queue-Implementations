#ifndef PRIORITY_QUEUE_FLAVOURS

#include <stdbool.h>

struct Node;

// We need to use void pointers because the structure of the heap/queue
//  nodes changes depending on implementation
void insert(struct Node** implementation, int newNum);

int pop(struct Node** implementation);


void runHeapTest(int elements, int firstDumpAmmount);
void runPrintedHeapTest(int elements, int firstDumpAmmount);

void printArbitaryData(struct Node* queue);


#define PRIORITY_QUEUE_FLAVOURS
#endif