#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#define QUEUE_SIZE 10

int main(void)
{
    QUEUE *queue;
    queue = CreateQueue(QUEUE_SIZE);

    int x;

    printf("\nDeQueue from empty queue\n-----------------------\n");
    DeQueue(queue, &x);

    printf("\nEnQueue 11 number\n------------------\n");
    for (int i = 0; i < 11; i++)
    {
        if (EnQueue(queue, i))
            printf("EnQueued %d\n", i);
    }

    printf("\nPeek\n------------------\n");
    if (Peek(queue, &x))
        printf("Peeked %d\n", x);

    printf("\nDeQueue 2 number\n------------------\n");
    if (DeQueue(queue, &x))
        printf("DeQueued %d\n", x);

    if (DeQueue(queue, &x))
        printf("DeQueued %d\n", x);

    printf("\nPeek\n------------------\n");
    if (Peek(queue, &x))
        printf("Peeked %d\n", x);

    printf("\nEnQueue 15, 16 number\n----------------------\n");
    x = 15;
    if (EnQueue(queue, x))
        printf("EnQueued %d\n", 15);
    x = 16;
    if (EnQueue(queue, x))
        printf("EnQueued %d\n", x);

    printf("\nDeQueue all\n--------------\n");
    while (!IsEmpty(queue))
    {
        if (DeQueue(queue, &x))
            printf("DeQueued %d\n", x);
    }

    printf("\nDeQueue from empty queue\n-----------------------\n");
    if (DeQueue(queue, &x))
        printf("DeQueued %d\n", x);

    printf("\nDestroy queue\n------------------\n");
    DestroyQueue(queue);
    return 0;
}
