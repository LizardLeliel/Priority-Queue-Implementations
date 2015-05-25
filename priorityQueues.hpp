#ifndef PRIORITY_QUEUE_FLAVOURS
#define PRIORITY_QUEUE_FLAVOURS

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

class PriorityQueue
{

  public:
    PriorityQueue() {}
    virtual ~PriorityQueue() {}

    virtual bool isEmpty()            = 0;
    virtual unsigned int pop()        = 0;
    virtual void insert(unsigned int) = 0;
    virtual std::string getName()     = 0;
    virtual void printQueue()         = 0;

};

void runRandomPriorityQueueTest(unsigned int insertAmmount, PriorityQueue* heap)
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


class UnsortedCircularList : public PriorityQueue
{
  public:
    UnsortedCircularList();
    ~UnsortedCircularList();

    bool isEmpty();
    unsigned int pop();
    void insert(unsigned int inValue);
    std::string getName();
    void printQueue();

  private:
    void removeNode();

    struct QueueNode
    {
        unsigned int value;
        QueueNode* next;
        QueueNode(unsigned int inValue) { value = inValue; }
    } *queue;

};

class ArrayHeap : public PriorityQueue
{
  public:
    ArrayHeap(unsigned int maxValue);
    ~ArrayHeap();

    bool isEmpty();
    unsigned int pop();
    void insert(unsigned int inValue);
    std::string getName();
    void printQueue();

  private:
    unsigned int currentNext;
    unsigned int* heapArray;

};
#endif