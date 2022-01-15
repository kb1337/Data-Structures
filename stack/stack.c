#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define EMPTY -1

void *AllocateMemory(int size, const char *strErr, bool bExit)
{
    void *pvMem = malloc(size);

    if (NULL == pvMem)
    {
        printf("Memory allocation failure: %s", strErr);

        if (bExit)
            exit(EXIT_FAILURE);
    }

    return pvMem;
}

STACK *CreateStack(int size)
{
    STACK *stack = AllocateMemory(sizeof(STACK), "CreateStack stack", EXIT_PROGRAM);
    stack->data = AllocateMemory(sizeof(int) * size, "CreateStack data", EXIT_PROGRAM);
    stack->size = size;
    stack->sp = EMPTY;

    return stack;
}

bool IsFull(STACK *stack)
{
    return (stack->sp == stack->size - 1);
    // return (stack != NULL && (stack->sp == stack->sp));
}

bool IsEmpty(STACK *stack)
{
    return (stack->sp == EMPTY);
}

bool Push(STACK *stack, int data)
{
    if (NULL != stack)
    {
        if (!IsFull(stack))
        {
            stack->sp++;
            stack->data[stack->sp] = data;
            return true;
        }
        else
        {
            printf("Stack is full\n");
        }
    }

    return false;
}

bool Peek(STACK *stack, int *pData)
{
    if (NULL != stack)
    {
        if (!IsEmpty(stack))
        {
            *pData = stack->data[stack->sp];
            return true;
        }
        else
        {
            printf("Stack is empty\n");
        }
    }

    return false;
}

bool Pop(STACK *stack, int *pData)
{
    if (NULL != stack)
    {
        if (!IsEmpty(stack))
        {
            *pData = stack->data[stack->sp];
            stack->sp--;
            return true;
        }
        else
        {
            printf("Stack is empty\n");
        }
    }

    return false;
}

void DestroyStack(STACK *stack)
{
    if (NULL != stack)
    {
        free(stack->data);
        free(stack);
    }
}
