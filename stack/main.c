#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 10

int main(void)
{
    STACK *stack = NULL;
    int x;

    stack = CreateStack(STACK_SIZE);

    // Peek from empty stack
    if (Peek(stack, &x))
        printf("\nPeeked %d\n\n", x);

    for (int i = 0; i < stack->size + 1; i++)
    {
        if (Push(stack, i))
            printf("Pushed %d\n", i);
    }

    if (Peek(stack, &x))
        printf("\nPeeked %d\n\n", x);

    stack->sp--;
    printf("stack poiter -1\n");

    if (Peek(stack, &x))
        printf("\nPeeked %d\n\n", x);

    // Pop every item
    while (!IsEmpty(stack))
    {
        if (Pop(stack, &x))
            printf("Popped %d\n", x);
        else
            printf("Popped %d\n", x);
    }

    // Pop from empty stack
    Pop(stack, &x);

    DestroyStack(stack);

    return 0;
}
