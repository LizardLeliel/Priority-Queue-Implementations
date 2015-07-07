#ifndef PRIORITY_QUEUE_FLAVOURS
#define PRIORITY_QUEUE_FLAVOURS

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

template<typename Type> class PriorityQueue
{

  public:
    PriorityQueue() {}
    virtual ~PriorityQueue() {}

    virtual bool isEmpty()            = 0;
    virtual Type pop()                = 0;
    virtual void insert(Type)         = 0;
    virtual std::string getName()     = 0;
    virtual void printQueue()         = 0;

};


// template<typename Type> class UnsortedCircularList 
//     : public PriorityQueue<Type>
// {
//   public:
//     UnsortedCircularList<Type>();
//     ~UnsortedCircularList<Type>();

//     bool isEmpty();
//     Type pop();
//     void insert(Type inValue);
//     std::string getName();
//     void printQueue();

//   private:
//     void removeNode();

//     struct QueueNode
//     {
//         Type value;
//         QueueNode* next;
//         QueueNode(Type inValue) { value = inValue; }
//     } *queue;

// };

// template<typename Type>class ArrayHeap 
//     : public PriorityQueue<Type>
// {
//   public:
//     ArrayHeap(unsigned int maxValue);
//     ~ArrayHeap();

//     bool isEmpty();
//     Type pop();
//     void insert(Type inValue);
//     std::string getName();
//     void printQueue();

//   private:
//     unsigned int currentNext;
//     Type* heapArray; // Array

// };

#endif