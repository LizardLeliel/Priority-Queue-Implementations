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

/*****************************************************************************
 * ARRAY HEAP IMPLEMENTATION OF PRIORITY QUEUE
 */
#if IMPLEMENTATION == ARRAY_HEAP

char implementationName[64] = "Array Heap";

struct Node
{
    int currentNext;
    int* numbers;
};

void initialize(struct Node** heap, int max)
{
    struct Node* iniNode = malloc(sizeof(struct Node));
    iniNode->currentNext = 0;
    iniNode->numbers     = calloc(sizeof(int), max + 2);


    if (iniNode->numbers == NULL) exit(-1); // Explain with printing
    *heap                = iniNode;
}

void insert(struct Node** heap, int newNum)
{
    int bottomNum, topNum;
    struct Node* quickRef = *heap;
    int* numbersRef       = (*heap)->numbers;
    bottomNum             = (*heap)->currentNext;

    // Initial insert
    numbersRef[bottomNum] = newNum;

    // Do the sort
    while (bottomNum != 0)
    {
        // The result is half the highest even number below bottomNum
        topNum = (bottomNum - 2 + (bottomNum & 1)) >> 1;

        if (numbersRef[topNum] < newNum)
        {
            numbersRef[bottomNum] = numbersRef[topNum];
            numbersRef[topNum]    = newNum;
        }
        else break;

        bottomNum = topNum;
    }

    ++(quickRef->currentNext);

}

int pop(struct Node** heap)
{
    // Todo: Make things so much nicer
    struct Node* qref = *heap;
    int* numbersRef   = qref->numbers;
    int returnVal     = numbersRef[0];
    int topNum        = 0;
    int leftNum       = 1;
    int rightNum;

    // Swap the bottom and top, decrement the next free slot
    --(qref->currentNext);
    numbersRef[0] = numbersRef[qref->currentNext];
    numbersRef[qref->currentNext] = 0;

    // Note: it doesn't matter if it checks a branch with only one leaf.
    //  The unused leaf will always be 0, and it will never swap with it
    while (leftNum < qref->currentNext)
    {
        rightNum = leftNum + 1;
        // Assign left num to be the index of the higher leaf. I know its odd
        if (numbersRef[leftNum] < numbersRef[rightNum]) 
            {++leftNum; --rightNum;}

        // If "left" is bigger then the current (note: Fix these names!!!)
        if (numbersRef[topNum] < numbersRef[leftNum])
        {   
            int swapNum = numbersRef[topNum];
            numbersRef[topNum]   = numbersRef[leftNum];
            numbersRef[leftNum]  = swapNum;
            topNum               = leftNum;
            leftNum              = topNum*2 + 1;
        } // Else if right is
        else if (numbersRef[topNum] < numbersRef[rightNum])
        {
            int swapNum = numbersRef[topNum];
            numbersRef[topNum]   = numbersRef[rightNum];
            numbersRef[rightNum] = swapNum;
            topNum               = rightNum;
            leftNum              = topNum*2 + 1;
        }
        else break;
    }
    return returnVal;
}

bool empty(struct Node* heap)
{
    return (bool)heap->currentNext;
}

void printQueue(struct Node* heap)
{
    // Note: Possibly seperate the layers?
    for (int i = 0, m = 1, q = 1; i < heap->currentNext; ++i, ++m)
    {
        printf("%d (%d), ", heap->numbers[i], i);
        if (m == q)
        {
            putchar('\n');
            for (int a=0; a < 78; ++a) putchar('=');
            putchar('\n');
            m = 0; q <<= 1;
        }
    }
    putchar('\n');
}

#elif IMPLEMENTATION == ARRAYLESS_HEAP

/*****************************************************************************
 * SORTED CIRCULAR LIST IMPLEMENTATION OF PRIORITY QUEUE
 */
#elif IMPLEMENTATION == SORTED_CIRCLE_LIST

char implementationName[64] = "Sorted circular list";

struct Node
{
    int number;
    struct Node* next;
 };

// Ma
void initialize(struct Node** implementation, int max)
{
    return;
}

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
        struct Node* tracer = *queue;
        do
        {
            if (newNum > tracer->number)
            {
                struct Node* newNode = malloc(sizeof(struct Node));
                *newNode             = *tracer;
                tracer->next         = newNode;
                tracer->number       = newNum;
                return; //<- Prevents a redundant if statement
            }

            tracer = tracer->next;
        } while (tracer != *queue);

        // If the new number is the lowest, then we need to change the
        //  reference pointer
        struct Node* newNode = malloc(sizeof(struct Node));
        *newNode             = *tracer;
        tracer->number       = newNum;
        tracer->next         = newNode;
        *queue               = newNode;
    }
}

int pop(struct Node** queue)
{
    struct Node* toFree = (*queue)->next;
    int returnVal       = toFree->number;

    if (*queue == toFree)
    {
        *queue = NULL;
    }
    else
    {
        **queue = *toFree;
    }

    free(toFree);
    return returnVal;
}

bool empty(struct Node* queue)
{
    return (bool)queue;
}

void printQueue(struct Node* queue)
{
    struct Node* tracer = queue;

    do
    {
        printf("%d, ", tracer->number);
        tracer = tracer->next;
    } while (tracer != queue);

    putchar('\n');
}

/*****************************************************************************
 * SORTED_LIST IMPLEMENATION OF PRIORITY QUEUE
 */
#elif IMPLEMENTATION == SORTED_LIST

char implementationName[64] = "Sorted list";

struct Node
{
    int number;
    struct Node* next;
};

void initialize(struct Node** implementation, int max)
{
    return;
}

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
    int returnVal       = toFree->number;

    *queue = toFree->next;

    free(toFree);
    return returnVal;
}

bool empty(struct Node* queue)
{
    return (bool)queue;
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
 * NAIVE_QUEUE IMPLEMENATION OF PRIORITY QUEUE
 */
#elif IMPLEMENTATION == CIRCLE_LIST

char implementationName[64] = "Unsorted Circular list";

struct Node 
{ 
    int number;
    struct Node* next;
};

void initialize(struct Node** implementation, int max)
{
    return;
}

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

bool empty(struct Node* queue)
{
    return (bool)queue;
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
    initialize(&priorityQueue, elements);
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
    while (empty(priorityQueue)) pop(&priorityQueue);

    return;
}

// VERY close to the first one
void runPrintedHeapTest(int elements, int firstDumpAmmount)
{
    // Initialize a couple of things
    struct Node* priorityQueue = NULL;
    initialize(&priorityQueue, elements);
    srand(time(NULL));
    int halfwayMark = elements/2;


    if (firstDumpAmmount > halfwayMark)
    {
        printf("Error: asked to pop more elements midayway then half the");
        printf(" total nodes\n");
        exit(-2);
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
    printf("Success");
    printf("\n All the numbers from highest to lowest: ");

    // Pop the rest (which should also free the memory)
    while (empty(priorityQueue)) printf("%d, ", pop(&priorityQueue));
    putchar('\n');

    return;
}

