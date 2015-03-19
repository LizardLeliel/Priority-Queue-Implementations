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

    HeapBase* heap = new UnsortedCircularList();
    cout << "Current heap implementation: " << heap->getName() << std::endl;

    runRandomHeapTest(100, heap);

    delete heap;

    puts("Goodbye, world!");
    return 0;

}