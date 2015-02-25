#ifndef PRIORITY_QUEUE_FLAVOURS

#include <stdbool.h>

struct Node;

#define IMPLEMENTATION SORTED_CIRCLE_LIST
/* Currently implementation macros:
 *  - CIRCLE_LIST
 *  - SORTED_LIST
 * Define IMPLEMENATION as one of the above
 */

void insert(struct Node** implementation, int newNum);
int pop(struct Node** implementation);
void printQueue(struct Node* queue);

void runHeapTest(int elements, int firstDumpAmmount);
void runPrintedHeapTest(int elements, int firstDumpAmmount);


extern char implementationName[64];

#define PRIORITY_QUEUE_FLAVOURS
#endif