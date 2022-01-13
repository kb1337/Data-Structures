# Doubly Linked List
Structure

```c
typedef struct DLLI
{
    int data;
    struct DLLI *prev;
    struct DLLI *next;
} DLLI;
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
Iterative appoach

```c
void PrintList(DLLI *head)
{
    if (NULL == head)
        return;

    while (NULL != head)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}
```
</p>
</details>

<details><summary>Add item to end of the list</summary>
<p>

```c
DLLI *AddItemToEnd(DLLI *head, int data)
{
    DLLI *newItem = AllocateMemory(sizeof(DLLI), "AddItemToEnd", EXIT_PROGRAM);
    newItem->prev = NULL;
    newItem->next = NULL;
    newItem->data = data;

    if (NULL == head)
        return newItem;

    DLLI *tmp = head;
    while (NULL != tmp->next)
        tmp = tmp->next;

    tmp->next = newItem;
    newItem->prev = tmp;

    return head;
}
```
</p>
</details>

<details><summary>Add item to head of the list</summary>
<p>
New item will be the head of the list.

```c
DLLI *AddItemToHead(DLLI *head, int data)
{
    DLLI *newItem = AllocateMemory(sizeof(DLLI), "AddItemToHead", EXIT_PROGRAM);
    newItem->prev = NULL;
    newItem->next = head;
    newItem->data = data;

    return newItem;
}
```
</p>
</details>

<details><summary>Destroy the list</summary>
<p>
Free every item recursively from last to first.

```c
void DestroyList(DLLI *head)
{
    if (NULL == head)
        return;

    DestroyList(head->next);
    free(head);
}
```

</p>
</details>

