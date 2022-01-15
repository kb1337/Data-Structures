# Stack

Structure

```c
typedef struct tagStack
{
    int sp;
    int size;
    int *data;
} STACK;
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

<details><summary>Create stack</summary>
<p>

```c
STACK *CreateStack(int size)
{
    STACK *stack = AllocateMemory(sizeof(STACK), "CreateStack stack", EXIT_PROGRAM);
    stack->data = AllocateMemory(sizeof(int) * size, "CreateStack data", EXIT_PROGRAM);
    stack->size = size;
    stack->sp = EMPTY;

    return stack;
}
```
</p>
</details>

<details><summary>Is full</summary>
<p>
Check if stack is full

```c
bool IsFull(STACK *stack)
{
    return (stack != NULL && (stack->sp == stack->size - 1));
}
```
</p>
</details>

<details><summary>Is empty</summary>
<p>
Check if stack is empty

```c
bool IsEmpty(STACK *stack)
{
    return (stack != NULL && (stack->sp == EMPTY));
}
```
</p>
</details>

<details><summary>Push</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>Peek</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>Pop</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>Destroy stack</summary>
<p>

```c
void DestroyStack(STACK *stack)
{
    if (NULL != stack)
    {
        free(stack->data);
        free(stack);
    }
}
```
</p>
</details>

