#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "priorityQueues.h"

int main(int argc, char** argv)
{
    printf("Hello, world!\n");

    // Make a less lazy arg parsing implementation soon, me
    if (argc < 3) return -1;
    puts(implementationName);
    runHeapTest(atoi(argv[1]), atoi(argv[2]));

    printf("Goodbye, world!\n");
    return 0;

}