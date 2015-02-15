#ifndef PRIORITY_QUEUE_FLAVOURS

#include <stdbool.h>

struct Node;

// I lied; no void pointers needed
void insert(struct Node** implementation, int newNum);
int pop(struct Node** implementation);
void printQueue(struct Node* queue);

void runHeapTest(int elements, int firstDumpAmmount);
void runPrintedHeapTest(int elements, int firstDumpAmmount);


extern char implementationName[64];

#define PRIORITY_QUEUE_FLAVOURS
#endif