#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <string>
#include <iostream>

#include "priorityQueues.hpp"

using namespace std;

int main(int argc, char** argv)
{
    puts("Hello, world!\n");

    // Make a less lazy arg parsing implementation soon, me
    if (argc < 0) return -1;

    PriorityQueue* priorityQueue = new ArrayHeap(100);
    cout << "Current priority queue implementation: " << priorityQueue->getName() << std::endl;

    runRandomPriorityQueueTest(100, priorityQueue);

    delete priorityQueue;

    puts("Goodbye, world!");
    return 0;

}