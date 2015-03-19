#ifndef UNSORT_CIRCLE_LIST
#include "priorityQueues.hpp"

#include <string>
#include <iostream>
#include <cstdlib>

using std::string;
//using std::NULL;

UnsortedCircularList::UnsortedCircularList()
{
    queue = NULL;
}

UnsortedCircularList::~UnsortedCircularList()
{
    // Is it safe to return from a destructor?
    if (queue == NULL);
    else if (queue->next == queue)
    {
        delete queue;
        queue = NULL;
    }
    else
    {
        QueueNode* tracer   = queue->next;
        QueueNode* toDelete = tracer;
        queue->next         = NULL;
        while (tracer != NULL)
        {
            toDelete = tracer;
            tracer  = tracer->next;
            delete toDelete;
        }
    }
}

void UnsortedCircularList::insert(unsigned int inValue) 
{
    //using UnsortedCircularList::QueueNode;
    QueueNode* newNode = new QueueNode(inValue);
    if (queue == NULL)
    {
        newNode->next = newNode;
        queue         = newNode;
    }
    else
    {
        newNode->next = queue->next;
        queue->next   = newNode;
    }
}

// I'm keeping it here because the only place its used is pop
void UnsortedCircularList::removeNode() 
{
    QueueNode* toFree = queue->next;

    // If there's only one node left
    if (queue == toFree)
    {
        queue = NULL;
    }
    else
    {
        *queue = *toFree;
    }
    delete toFree;
}

unsigned int UnsortedCircularList::pop() 
{
    if (queue == NULL) return 0;

    QueueNode* finder = queue;
    QueueNode* record = finder;

    // Note: 0 is suposed to be the minimum value of an unsigned int
    unsigned int priority = 0;

    // Basically, we go through every value, looking for the highest one
    do
    {
        if (finder->value >= priority)
        {
            record   = finder;
            priority = finder->value;
        }

        finder = finder->next;
    } while (finder != queue);

    queue = record;
    removeNode();

    return priority;

}

bool UnsortedCircularList::isEmpty()
{
    return (queue == NULL);
}

string UnsortedCircularList::getName()
{
    return "Unsorted Circular List";
}

void UnsortedCircularList::printQueue() {}

/* I needed /somewhere/ to put it! */
void runRandomHeapTest(unsigned int insertAmmount, HeapBase* heap)
{
    srand(time(NULL));

    for (int i = 0; i < insertAmmount; ++i)
    {
        heap->insert(rand());
    }
    while (!heap->isEmpty())
    {
        std::cout << heap->pop() << ", ";
    }
    std::cout << std::endl;
}


#define UNSORT_CIRCLE_LIST
#endif