#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

void *AllocateMemory(int size, const char *strErr, bool bExit)
{
    void *pvMem = malloc(size);
    if (NULL == pvMem)
    {
        fprintf(stderr, "Memory allocation failure: %s", strErr);
        if (bExit)
        {
            exit(EXIT_FAILURE);
            return NULL;
        }
    }

    return pvMem;
}

QUEUE *CreateQueue(int size)
{
    QUEUE *newQueue = AllocateMemory(sizeof(QUEUE), "CreateQueue newQueue", EXIT_PROGRAM);
    int *pData = AllocateMemory(sizeof(int) * size, "CreateQueue pData", EXIT_PROGRAM);
    newQueue->pData = pData;
    newQueue->size = size;
    newQueue->front = 0;
    newQueue->rear = 0;
    newQueue->itemCount = 0;

    return newQueue;
}

bool IsEmpty(QUEUE *pQueue)
{
    return (pQueue->itemCount == 0);
}

bool IsFull(QUEUE *pQueue)
{
    return (pQueue->itemCount == pQueue->size);
}

bool Peek(QUEUE *pQueue, int *pData)
{
    if (NULL != pQueue)
    {
        if (!IsEmpty(pQueue))
        {
            *pData = pQueue->pData[pQueue->front];
            return true;
        }
    }

    return false;
}

bool EnQueue(QUEUE *pQueue, int data)
{
    if (NULL != pQueue)
    {
        if (!IsFull(pQueue))
        {
            pQueue->pData[pQueue->rear] = data;
            pQueue->rear = (pQueue->rear + 1) % pQueue->size;
            pQueue->itemCount++;
            return true;
        }
        printf("Queue is full\n");
    }

    return false;
}

bool DeQueue(QUEUE *pQueue, int *pData)
{
    if (NULL != pQueue)
    {
        if (!IsEmpty(pQueue))
        {
            *pData = pQueue->pData[pQueue->front];
            pQueue->front = (pQueue->front + 1) % pQueue->size;
            pQueue->itemCount--;
            return true;
        }
        printf("Queue is empty\n");
    }

    return false;
}

void DestroyQueue(QUEUE *pQueue)
{
    if (NULL != pQueue)
    {
        free(pQueue->pData);
        free(pQueue);
    }
}
