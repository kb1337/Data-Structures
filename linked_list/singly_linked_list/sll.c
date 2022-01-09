#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sll.h"

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

void PrintList_Recursive(SLLI *head)
{
    if (NULL == head)
        return;

    printf("%d\n", head->data);
    PrintList_Recursive(head->next);
}

void PrintListReverse(SLLI *head)
{
    if (NULL == head)
        return;

    PrintListReverse(head->next);
    printf("%d\n", head->data);
}

SLLI *DeleteItemFromList(SLLI *head, int toDel);
SLLI *DeleteItemFromList_Recursive(SLLI *head, int toDel);

void DestroyList(SLLI *head)
{
    if (NULL == head)
        return;

    DestroyList(head->next);
    free(head);
}
