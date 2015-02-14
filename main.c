#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "priorityQueues.h"

int main(int argc, char** argv)
{
    printf("Hello, world!\n");

    struct Node* thisThing = NULL;

    insert(&thisThing, 4);
    insert(&thisThing, 6);
    insert(&thisThing, 5);
    printQueue(thisThing);
    printf("Highest: %d\n", pop(&thisThing));
    //printQueue(thisThing);

    printf("Goodbye, world!\n");
    return 0;


}