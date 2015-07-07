#include "priorityQueues.hpp"

#include <string>
#include <iostream>
#include <cstdlib>

using std::string;
//using std::NULL;

template<typename Type> class UnsortedCircularList 
    : public PriorityQueue<Type>
{
  public:
    UnsortedCircularList<Type>();
    ~UnsortedCircularList<Type>();

    bool isEmpty();
    Type pop();
    void insert(Type inValue);
    std::string getName();
    void printQueue();

  private:
    void removeNode();

    struct QueueNode
    {
        Type value;
        QueueNode* next;
        QueueNode(Type inValue) { value = inValue; }
    } *queue;

};

template<typename Type>
UnsortedCircularList<Type>::UnsortedCircularList()
{
    queue = NULL;
}

template<typename Type>
UnsortedCircularList<Type>::~UnsortedCircularList()
{
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

template<typename Type>
void UnsortedCircularList<Type>::insert(Type inValue) 
{
    //using UnsortedCircularList<Type>::QueueNode;
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
template<typename Type>
void UnsortedCircularList<Type>::removeNode() 
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

template<typename Type>
Type UnsortedCircularList<Type>::pop() 
{
    if (queue == NULL) return 0;

    QueueNode* finder = queue;
    QueueNode* record = finder;

    // Note: 0 is suposed to be the minimum value of an unsigned int
    Type priority = 0;

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

template<typename Type>
bool UnsortedCircularList<Type>::isEmpty()
{
    return (queue == NULL);
}

template<typename Type>
string UnsortedCircularList<Type>::getName()
{
    return "Unsorted Circular List";
}

template<typename Type>
void UnsortedCircularList<Type>::printQueue() {}

