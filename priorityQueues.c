#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

#include "priorityQueues.h"

#define CIRCLE_LIST 0
#define DIRECTION_QUEUE 1
#define ARRAY_HEAP 2
#define IMPLEMENTATION CIRCLE_LIST

#ifndef IMPLEMENTATION
 #error IMPLEMENTATION must be defined as a macro of value 0, 1, or 2
#endif

#if IMPLEMENTATION == ARRAY_HEAP

#elif IMPLEMENTATION == DIRECTION_QUEUE



/*****************************************************************************
 * NAIVE_QUEUE IMPLEMENATION OF PIRORITY QUEUE
 */
#elif IMPLEMENTATION == CIRCLE_LIST

struct Node 
{ 
    int number;
    struct Node* next;
};

void insert(struct Node** queue, int newNum)
{
    if (*queue == NULL)
    {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->number      = newNum;
        newNode->next        = newNode;
        *queue               = newNode;
    }
    else
    {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->number      = newNum;
        newNode->next        = (*queue)->next;
        (*queue)->next       = newNode; 
    }
}

void removeNode(struct Node** queue)
{
    // Instead of deleting the current node, we copy the contents 
    //  of the next node, and delete /that/. It allows the list
    //  to be unbroken without going through the entire list to fix
    //  the ->next right before the current node
    struct Node* toFree = (*queue)->next;

    // If there's only one node left
    if (*queue == toFree)
    {
        *queue = NULL;
    }
    else
    {
        **queue = *toFree;
    }

    free(toFree);

}

int pop(struct Node** queue)
{
    if (queue == NULL || *queue == NULL)
    {
        printf("Warning: emptey queue");
        return 0;
    }
    
    struct Node* finder = *queue;
    struct Node* record = finder;
    int priority = INT_MIN;
    do
    {
        if (finder->number > priority)
        {
            record   = finder;
            priority = finder->number;
        }

        finder = finder->next;

    } while (record != finder);
    *queue = finder;
    removeNode(queue);
    return priority;

}


void printQueue(struct Node* queue)
{
    struct Node* tracer = queue;
    if (tracer == NULL) return;
    do
    {
        printf("%d, ", tracer->number);
        tracer = tracer->next;
    } while (tracer != queue);
    putchar('\n');

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
