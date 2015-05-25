#ifndef ARRAY_HEAP

#include "priorityQueues.hpp"

#include <string>
#include <iostream>

using namespace std;

ArrayHeap::ArrayHeap(unsigned int maxValue)
{
    currentNext = 0;
    heapArray   = new unsigned int[maxValue](); // This sets all values to 0
}

ArrayHeap::~ArrayHeap()
{
    delete heapArray; // Is this right?
}

void ArrayHeap::insert(unsigned int inValue)
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

unsigned int ArrayHeap::pop()
{
    int returnVal  = heapArray[0];
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
            int swapNum = heapArray[higherRef];
            heapArray[higherRef] = heapArray[firstLeaf];
            heapArray[firstLeaf] = swapNum;
            higherRef            = firstLeaf;
            firstLeaf            = higherRef*2 + 1;
        }

        else if (heapArray[higherRef] < heapArray[secondLeaf])
        {
            int swapNum = heapArray[higherRef];
            heapArray[higherRef]  = heapArray[secondLeaf];
            heapArray[secondLeaf] = swapNum;
            higherRef             = secondLeaf;
            firstLeaf             = higherRef*2 + 1;
        }

        else break;
    }
    
    return returnVal;
}
bool ArrayHeap::isEmpty()
{
    return (currentNext == 0);
}

string ArrayHeap::getName()
{
    return "Heap (using an array)";
}

void ArrayHeap::printQueue()
{
    std::cout << "o-o" << std::endl;
}


#define ARRAY_HEAP
#endif