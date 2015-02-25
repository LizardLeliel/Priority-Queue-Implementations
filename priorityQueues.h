#ifndef PRIORITY_QUEUE_FLAVOURS

#include <stdbool.h>

struct Node;

#define IMPLEMENTATION ARRAY_HEAP
/* Currently implementation macros:
 *  - CIRCLE_LIST
 *  - SORTED_LIST
 * Define IMPLEMENATION as one of the above
 */

void initialize(struct Node** implementation, int max);
void insert(struct Node** implementation, int newNum);
int pop(struct Node** implementation);
bool empty(struct Node* implementation);
// Do the next line later
//void destroy(struct Node** implementation);
void printQueue(struct Node* queue);


void runHeapTest(int elements, int firstDumpAmmount);
void runPrintedHeapTest(int elements, int firstDumpAmmount);


extern char implementationName[64];

#define PRIORITY_QUEUE_FLAVOURS
#endif