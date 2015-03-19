#ifndef PRIORITY_QUEUE_FLAVOURS
#define PRIORITY_QUEUE_FLAVOURS

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

class HeapBase
{

  public:
    HeapBase() {}
    virtual ~HeapBase() {}

    virtual bool isEmpty()            = 0;
    virtual unsigned int pop()        = 0;
    virtual void insert(unsigned int) = 0;
    virtual std::string getName()     = 0;
    virtual void printQueue()         = 0;

};

// Maybe move this to another file?
void runRandomHeapTest(unsigned int insertAmmount, HeapBase* heap);

class UnsortedCircularList : public HeapBase
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

// All the refactor! ... The code below is the old C code, all commented out

//#include <stdbool.h>

//struct Node;

//#define IMPLEMENTATION ARRAY_HEAP
/* Currently implementation macros:
 *  - CIRCLE_LIST
 *  - SORTED_LIST
 * Define IMPLEMENATION as one of the above
 */

/*
void initialize(struct Node** implementation, int max);
void insert(struct Node** implementation, int newNum);
int pop(struct Node** implementation);
bool empty(struct Node* implementation);
// Do the next line later
//void destroy(struct Node** implementation);
void printQueue(struct Node* queue);


void runHeapTest(int elements, int firstDumpAmmount);
void runPrintedHeapTest(int elements, int firstDumpAmmount);
*/

//extern char implementationName[64];

//#define PRIORITY_QUEUE_FLAVOURS
#endif