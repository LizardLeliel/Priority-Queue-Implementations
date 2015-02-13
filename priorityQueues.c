#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "priorityQueues.h"

#define NAIVE_QUEUE 0
#define DIRECTION_QUEUE 1
#define ARRAY_HEAP 2
#define IMPLEMENTATION NAIVE_QUEUE

#ifndef IMPLEMENTATION
 #error IMPLEMENTATION must be defined as a macro of value 0, 1, or 2
#endif

#if IMPLEMENTATION == ARRAY_HEAP

#elif IMPLEMENTATION == DIRECTION_QUEUE



/*****************************************************************************
 * NAIVE_QUEUE IMPLEMENATION OF PIRORITY QUEUE
 */
#elif IMPLEMENTATION == NAIVE_QUEUE // NAIVE_QUEUE

struct Node 
{ 
    int m;
    struct Node* next;
};

void insert(struct Node** implementation, int newNum)
{
    return;
}

int pop(struct Node** implementation)
{
    return 0;
}





// Raise an error message saying you haven't picked an implementation
#else 
 #error IMPLEMENTATION must be defined as 0, 1, or 2
#endif

/*****************************************************************************
 * Runner function
 */

void runHeapTest(int elements, int dump, bool printOutput)
{
    return;
}
