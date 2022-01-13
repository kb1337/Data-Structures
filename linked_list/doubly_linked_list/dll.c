#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dll.h"

#define EXIT_PROGRAM true
#define DO_NOT_EXIT_PROGRAM false

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

DLLI *AddItemToHead(DLLI *head, int data)
{
    DLLI *newItem = AllocateMemory(sizeof(DLLI), "AddItemToHead", EXIT_PROGRAM);
    newItem->prev = NULL;

    newItem->next = head;

    if (NULL != head)
        head->prev = newItem;

    newItem->data = data;

    return newItem;
}

DLLI *AddItemInOrder(DLLI *head, int data);

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

void PrintList_Recursive(DLLI *head)
{
    if (NULL == head)
        return;

    printf("%d\n", head->data);
    PrintList_Recursive(head->next);
}

void PrintListReverse(DLLI *head)
{
    // Find last item
    while (NULL != head->next)
        head = head->next;

    // Print from last to first
    while (NULL != head)
    {
        printf("%d\n", head->data);
        head = head->prev;
    }
}

void PrintListReverse_Recursive(DLLI *head)
{
    if (NULL == head)
        return;

    PrintListReverse_Recursive(head->next);
    printf("%d\n", head->data);
}

DLLI *DeleteItemFromList(DLLI *head, int toDel);
DLLI *DeleteItemFromList_Recursive(DLLI *head, int toDel);

void DestroyList(DLLI *head)
{
    if (NULL == head)
        return;

    DestroyList(head->next);
    free(head);
}

DLLI *ReverseList(DLLI *head)
{
    DLLI *prev = NULL;
    DLLI *curr = head;
    DLLI *next = NULL;

    while (NULL != curr)
    {
        next = curr->next;

        curr->next = prev;
        curr->prev = next;

        prev = curr;
        curr = next;
    }

    return prev;
}
