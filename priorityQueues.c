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

void runHeapTest(int elements, int firstDumpAmmount)
{
    // Initialize a couple of things
    struct Node* priorityQueue = NULL;
    srand(time(NULL));
    int halfwayMark = elements/2;
    if (firstDumpAmmount > halfwayMark)
    {
        printf("Error: asked to pop more elements then half the total\n");

    }

    // Iterate over a bunch of random numbers
    for (int i=0; i < elements; ++i)
    {
        insert(&priorityQueue, rand());
        
        // Halfway through, pop an arbitary ammount of nodes
        if (i == halfwayMark)
        {
            for (int n=0; n < firstDumpAmmount; ++n)
            {
                pop(&priorityQueue);
            }
        }

    }

    // Pop the rest (which should also free the memory)
    while (priorityQueue != NULL) pop(&priorityQueue);

    return;
}
