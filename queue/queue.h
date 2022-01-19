#ifndef queue_h
#define queue_h

#define EXIT_PROGRAM true
#define DO_NOT_EXIT_PROGRAM false

typedef struct tagQueue
{
    int *pData;
    int size;
    int front;
    int rear;
    int itemCount;
} QUEUE;

void *AllocateMemory(int size, const char *strErr, bool bExit);

QUEUE *CreateQueue(int size);

bool IsEmpty(QUEUE *pQueue);
bool IsFull(QUEUE *pQueue);

bool EnQueue(QUEUE *pQueue, int data);
bool DeQueue(QUEUE *pQueue, int *pData);
bool Peek(QUEUE *pQueue, int *pData);

void DestroyQueue(QUEUE *pQueue);

#endif
