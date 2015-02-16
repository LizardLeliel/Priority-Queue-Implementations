#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

#include "priorityQueues.h"

#define CIRCLE_LIST 0
#define SORTED_LIST 1
#define SORTED_CIRCLE_LIST 2 // Maybe?
#define ARRAYLESS_HEAP 3
#define ARRAY_HEAP 4

#ifndef IMPLEMENTATION
 #error IMPLEMENTATION must be defined as an appriopriate macro
#endif

#if IMPLEMENTATION == ARRAY_HEAP

#elif IMPLEMENTATION == ARRAYLESS_HEAP

/*****************************************************************************
 * SORTED_LIST IMPLEMENATION OF PIRORITY QUEUE
 */
#elif IMPLEMENTATION == SORTED_LIST

char implementationName[64] = "Sorted list";

struct Node
{
    int number;
    struct Node* next;
};

void insert(struct Node** queue, int newNum)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->number      = newNum;

    if (*queue == NULL || (*queue)->number < newNum)
    {
        newNode->next = *queue;
        *queue        = newNode;   
    }
    // By the way: this implementation is slower then the circular list below
    else
    {
        struct Node* tracer = *queue;
        while (tracer->next != NULL && tracer->next->number > newNum)
        {
            tracer = tracer->next;
        }
        newNode->next = tracer->next;
        tracer->next  = newNode;
    }
}

int pop(struct Node** queue)
{
    struct Node* toFree = *queue;
    int returnVal = toFree->number;

    *queue = toFree->next;

    free(toFree);
    return returnVal;
}

void printQueue(struct Node* queue)
{
    while (queue != NULL)
    {
        printf("%d, ", queue->number);
        queue = queue->next;
    }
    putchar('\n');
}


/*****************************************************************************
 * NAIVE_QUEUE IMPLEMENATION OF PIRORITY QUEUE
 */
#elif IMPLEMENTATION == CIRCLE_LIST

char implementationName[64] = "Naive list (unsorted Circular list)";

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

// This is a helper function
void removeNode(struct Node** queue)
{
    // Instead of deleting the current node, we copy the contents 
    //  of the next node, and delete /that/. It allows the list
    //  to be unbroken without going through the entire list to fix
    //  the ->next right before the current node
    // Also: Error check for NULL pointertss
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
    
    // In this implementation, we go through the entire list, examining
    //  every node to see if it has the highest priority. Its the slowest
    //  part of this implemenation
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
 // Todo: implement function pointers to have the users test the 
 //  implementations at runtime
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
        printf("Error: asked to pop more elements midayway then half the");
        printf(" total nodes\n");
    }

    // Iterate through the random numbers
    for (int i = 0; i < halfwayMark; ++i)
    {
        insert(&priorityQueue, rand());
    }
    for (int i = 0; i < firstDumpAmmount; ++i)
    {
        pop(&priorityQueue);
    }
    for (int i = 0; i < halfwayMark; ++i)
    {
        insert(&priorityQueue, rand());
    }

    // Pop the rest (which should also free the memory)
    while (priorityQueue != NULL) pop(&priorityQueue);

    return;
}

// VERY close to the first one
void runPrintedHeapTest(int elements, int firstDumpAmmount)
{
    // Initialize a couple of things
    struct Node* priorityQueue = NULL;
    srand(time(NULL));
    int halfwayMark = elements/2;


    if (firstDumpAmmount > halfwayMark)
    {
        printf("Error: asked to pop more elements midayway then half the");
        printf(" total nodes\n");
    }

    // Iterate through the random numbers
    for (int i = 0; i < halfwayMark; ++i)
    {
        insert(&priorityQueue, rand());
    }
    for (int i = 0; i < firstDumpAmmount; ++i)
    {
        pop(&priorityQueue);
    }
    
    for (int i = 0; i < halfwayMark; ++i)
    {
        insert(&priorityQueue, rand());
    }

    printf("The numbers randomly generated: ");
    printQueue(priorityQueue);
    printf("\n All the numbers from highest to lowest: ");

    // Pop the rest (which should also free the memory)
    while (priorityQueue != NULL) printf("%d, ", pop(&priorityQueue));
    putchar('\n');

    return;
}

