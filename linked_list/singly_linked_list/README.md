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

<details><summary>Print in order</summary>
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

<details><summary>Print in reverse order</summary>
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
    SLLI *newItem = AllocateMemory(sizeof(SLLI), "AddItemToEnd", EXIT_PROGRAM);
    newItem->data = data;
    newItem->next = NULL;

    // First item of the list
    if (NULL == head)
        return newItem;

    // Find end of the list
    SLLI *tmp = head;
    while (NULL != tmp->next)
        tmp = tmp->next;

    // Last item found
    tmp->next = newItem;

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
    SLLI *newItem = AllocateMemory(sizeof(SLLI), "AddItemToHead", EXIT_PROGRAM);
    newItem->data = data;
    newItem->next = head;

    return newItem;
}
```
</p>
</details>

<details><summary>Add item in order</summary>
<p>

```c
SLLI *AddItemInOrder(SLLI *head, int data)
{
    SLLI *newItem = AllocateMemory(sizeof(SLLI), "AddItemInOrder", EXIT_PROGRAM);
    newItem->data = data;

    if (NULL == head)
    {
        newItem->next = NULL; // Add item to empty list
        return newItem;
    }

    if (data < head->data)
    {
        newItem->next = head; // Add item to head
        return newItem;
    }

    // Add item to middle or last
    SLLI *prev = NULL;
    SLLI *curr = head;
    while (NULL != curr && curr->data < data)
    {
        prev = curr;
        curr = curr->next;
    }

    newItem->next = prev->next;
    prev->next = newItem;

    return head;
}
```

</p>
</details>


<details><summary>Delete item</summary>
<p>
Iterative approach

```c
SLLI *DeleteItemFromList(SLLI *head, int toDel)
{
    if (NULL != head)
    {
        // Remove the head of the list
        if (toDel == head->data)
        {
            SLLI *newHead = head->next;
            free(head);
            return newHead;
        }

        // Remove middle or last item
        SLLI *prev = NULL;
        SLLI *curr = head;

        while (NULL != curr && toDel != curr->data)
        {
            prev = curr;
            curr = curr->next;
        }
        // After the loop, either list ended or target found

        if (NULL != curr)
        {
            // Target found
            prev->next = curr->next;
            free(curr);
        }
        else
        {
            printf("%d not found", toDel);
        }
    }
    return head;
}
```

Recursive approach

```c
SLLI *DeleteItemFromList_Recursive(SLLI *head, int toDel)
{
    if (NULL != head)
    {
        if (toDel == head->data)
        {
            SLLI *next = head->next;
            free(head);
            return next;
        }
        else
        {
            head->next = DeleteItemFromList_Recursive(head->next, toDel);
        }
    }
    return head;
}
```

</p>
</details>

<details><summary>Destroy the list</summary>
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

<details><summary>Reverse the list</summary>
<p>

```c
SLLI *ReverseList(SLLI *head)
{
    SLLI *prev = NULL;
    SLLI *curr = head;
    SLLI *next = NULL;

    while (NULL != curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
```

</p>
</details>