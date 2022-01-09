# Singly Linked List

Structure

```c
typedef struct SLLI
{
    int data;
    struct SLLI *next;
} SLLI;
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

<details><summary>Print a Linked List in order</summary>
<p>

Iterative approach

```c
void PrintList(SLLI *head)
{
    int counter = 1;
    while (NULL != head)
    {
        printf("%d: %d\n", counter, head->data);
        head = head->next;
        counter++;
    }
}
```

Recursive approach

```c
void PrintList_Recursive(SLLI *head)
{
    if (NULL == head)
        return;

    printf("%d\n", head->data);
    PrintList_Recursive(head->next);
}
```


</p>
</details>

<details><summary>Print a Linked List in reverse order</summary>
<p>
Recursive approach

```c
void PrintListReverse(SLLI *head)
{
    if (NULL == head)
        return;

    PrintList_Recursive(head->next);
    printf("%d\n", head->data);
}
```

</p>
</details>

<details><summary>Add item to end of the list</summary>
<p>

```c
SLLI *AddItemToEnd(SLLI *head, int data)
{
    SLLI *newNode = AllocateMemory(sizeof(SLLI), "AddItemToEnd", EXIT_PROGRAM);
    newNode->data = data;
    newNode->next = NULL;

    // First item of the list
    if (NULL == head)
        return newNode;

    // Find end of the list
    SLLI *tmp = head;
    while (NULL != tmp->next)
        tmp = tmp->next;

    // Last item found
    tmp->next = newNode;

    return head;
}
```
</p>
</details>


<details><summary>Add item to head of the list</summary>
<p>
New item will be the head of the list.

```c
SLLI *AddItemToHead(SLLI *head, int data)
{
    SLLI *newNode = AllocateMemory(sizeof(SLLI), "AddItemToHead", EXIT_PROGRAM);
    newNode->data = data;

    if (NULL == head)
        newNode->next = NULL; // First item of the list
    else
        newNode->next = head;

    return newNode;
}
```
</p>
</details>

<details><summary>Destroy List</summary>
<p>
Free every item recursively from last to first.

```c
void DestroyList(SLLI *head)
{
    if (NULL == head)
        return;

    DestroyList(head->next);
    free(head);
}
```

</p>
</details>