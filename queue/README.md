# Queue
Structure

```c
typedef struct tagQueue
{
    int *pData;
    int size;
    int front;
    int rear;
    int itemCount;
} QUEUE;
```

<details><summary>Allocate Memory</summary>
<p>

```c
void *AllocateMemory(int sizeBytes, const char *strErr, bool bExit)
{
    void *pvMem = malloc(sizeBytes);

    if (NULL == pvMem)
    {
        fprintf(stderr, "Memory allocation failure: %s\n", strErr);

        if (bExit)
            exit(EXIT_FAILURE);
    }

    return pvMem;
}
```
</p>
</details>

<details><summary>Create Queue</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>Is Empty</summary>
<p>

```c
bool IsEmpty(QUEUE *pQueue)
{
    return (pQueue->itemCount == 0);
}
```
</p>
</details>

<details><summary>Is Full</summary>
<p>

```c
bool IsFull(QUEUE *pQueue)
{
    return (pQueue->itemCount == pQueue->size);
}
```
</p>
</details>

<details><summary>Peek</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>EnQueue</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>DeQueue</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>Destroy Queue</summary>
<p>

```c
void DestroyQueue(QUEUE *pQueue)
{
    if (NULL != pQueue)
    {
        free(pQueue->pData);
        free(pQueue);
    }
}
```
</p>
</details>
