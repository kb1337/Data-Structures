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

    // Add item to empty list
    if (NULL == head)
        return newNode;

    // Find the last item
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
        newNode->next = NULL; // Add item to empty list
    else
        newNode->next = head;

    return newNode;
}

SLLI *AddItemInOrder(SLLI *head, int data)
{
    SLLI *newNode = AllocateMemory(sizeof(SLLI), "AddItemInOrder", EXIT_PROGRAM);
    newNode->data = data;

    if (NULL == head)
    {
        newNode->next = NULL; // Add item to empty list
        return newNode;
    }

    if (data < head->data)
    {
        newNode->next = head; // Add item to head
        return newNode;
    }

    // Add item to middle or last
    SLLI *prev = NULL;
    SLLI *curr = head;
    while (NULL != curr && curr->data < data)
    {
        prev = curr;
        curr = curr->next;
    }

    newNode->next = prev->next;
    prev->next = newNode;

    return head;
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
        // After the loop, either list has ended or target has found

        if (NULL != curr)
        {
            // Target found
            prev->next = curr->next;
            free(curr);
        }
        else
        {
            printf("%d not found\n", toDel);
        }
    }
    return head;
}

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

void DestroyList(SLLI *head)
{
    if (NULL == head)
        return;

    DestroyList(head->next);
    free(head);
}

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
