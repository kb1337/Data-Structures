#ifndef stack_h
#define stack_h

#define EXIT_PROGRAM true
#define DO_NOT_EXIT_PROGRAM false

typedef struct tagStack
{
    int *data;
    int sp;
    int size;
} STACK;

void *AllocateMemory(int size, const char *strErr, bool bExit);

STACK *CreateStack(int size);

bool IsFull(STACK *stack);
bool IsEmpty(STACK *stack);

bool Push(STACK *stack, int data);
bool Peek(STACK *stack, int *pData);
bool Pop(STACK *stack, int *pData);

void DestroyStack(STACK *stack);

#endif