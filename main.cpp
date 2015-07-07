#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <string>
#include <iostream>

#include "priorityQueues.hpp"
#include "arrayHeap.hpp"
#include "unsortedCircularList.hpp"

using namespace std;

void runRandomPriorityQueueTest
    (unsigned int insertAmmount, PriorityQueue<unsigned int>* pqueue)
{
    srand(time(NULL));

    for (int i = 0; i < insertAmmount; ++i)
    {
        pqueue->insert(rand());
    }
    while (!pqueue->isEmpty())
    {
        std::cout << pqueue->pop() << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    puts("Hello, world!\n");

    // Make a less lazy arg parsing implementation soon, me
    if (argc < 0) return -1;

    PriorityQueue<unsigned int>* priorityQueue 
        = new ArrayHeap<unsigned int>(100);
    cout << "Current priority queue implementation: " 
         << priorityQueue->getName() 
         << std::endl;

    runRandomPriorityQueueTest(100, priorityQueue);

    delete priorityQueue;

    puts("Goodbye, world!");
    return 0;

}