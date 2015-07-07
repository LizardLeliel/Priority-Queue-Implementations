#include "priorityQueues.hpp"

#include <string>
#include <iostream>

using namespace std;

template<typename Type>class ArrayHeap 
    : public PriorityQueue<Type>
{
  public:
    ArrayHeap(unsigned int maxValue);
    ~ArrayHeap();

    bool isEmpty();
    Type pop();
    void insert(Type inValue);
    std::string getName();
    void printQueue();

  private:
    unsigned int currentNext;
    Type* heapArray; // Array

};

template<typename Type> 
ArrayHeap<Type>::ArrayHeap(unsigned int maxValue)
{
    currentNext = 0;
    heapArray   = new unsigned int[maxValue](); // This sets all values to 0
}

template<typename Type> 
ArrayHeap<Type>::~ArrayHeap()
{
    delete heapArray; // Is this right?
}

template<typename Type> 
void ArrayHeap<Type>::insert(Type inValue)
{
    // -- add a potential overflow checking here --
    unsigned int lowerRef, higherRef;
    lowerRef = currentNext;

    heapArray[lowerRef] = inValue;

    while (lowerRef != 0)
    {
        // The result is half the highest even number below lowerRef
        higherRef = (lowerRef - 2 + (lowerRef & 1)) >> 1;

        if (heapArray[higherRef] < inValue)
        {
            heapArray[lowerRef]  = heapArray[higherRef];
            heapArray[higherRef] = inValue;
        }
        else break;

        lowerRef = higherRef;
    }

    ++currentNext;
}

template<typename Type> 
Type ArrayHeap<Type>::pop()
{
    Type returnVal  = heapArray[0];
    int higherRef  = 0;
    int firstLeaf  = 1;
    int secondLeaf; // Gets initialized within the while loop

    --currentNext;
    heapArray[0]           = heapArray[currentNext];
    heapArray[currentNext] = 0;

    while (firstLeaf < currentNext)
    {
        secondLeaf = firstLeaf + 1;

        if (heapArray[firstLeaf] < heapArray[secondLeaf])
            {++firstLeaf; --secondLeaf;}

        if (heapArray[higherRef] < heapArray[firstLeaf])
        {
            Type swap            = heapArray[higherRef];
            heapArray[higherRef] = heapArray[firstLeaf];
            heapArray[firstLeaf] = swap;
            higherRef            = firstLeaf;
            firstLeaf            = higherRef*2 + 1;
        }

        else if (heapArray[higherRef] < heapArray[secondLeaf])
        {
            Type swap             = heapArray[higherRef];
            heapArray[higherRef]  = heapArray[secondLeaf];
            heapArray[secondLeaf] = swap;
            higherRef             = secondLeaf;
            firstLeaf             = higherRef*2 + 1;
        }

        else break;
    }
    
    return returnVal;
}

template<typename Type>
bool ArrayHeap<Type>::isEmpty()
{
    return (currentNext == 0);
}

template<typename Type>
string ArrayHeap<Type>::getName()
{
    return "Heap (using an array)";
}

template<typename Type>
void ArrayHeap<Type>::printQueue()
{
    std::cout << "o-o" << std::endl;
}
