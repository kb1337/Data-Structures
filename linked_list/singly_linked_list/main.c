#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sll.h"

int main(void)
{
    SLLI *head = NULL;

    head = DeleteItemFromList(head, 1);           // empty list
    head = DeleteItemFromList_Recursive(head, 1); // empty list

    for (int i = 10; i < 20; i++)
    {
        head = AddItemToEnd(head, i);
    }

    printf("\n--- In order ---\n");
    PrintList(head);
    // PrintList_Recursive(head);

    printf("\n--- In reverse order ---\n");
    PrintListReverse(head);

    for (int i = 11; i > 0; i--)
    {
        head = AddItemToHead(head, i);
    }

    printf("\n--- In order ---\n");
    PrintList(head);

    printf("\n--- Delete head, middle, last item ---\n");
    head = DeleteItemFromList(head, 1);  // first item
    head = DeleteItemFromList(head, 15); // middle item
    head = DeleteItemFromList(head, 19); // last item
    head = DeleteItemFromList(head, 25); // not found

    printf("\n--- In order ---\n");
    PrintList(head);

    head = DeleteItemFromList_Recursive(head, 2);  // first item
    head = DeleteItemFromList_Recursive(head, 14); // middle item
    head = DeleteItemFromList_Recursive(head, 18); // last item
    head = DeleteItemFromList_Recursive(head, 30); // not found

    printf("\n--- In order ---\n");
    PrintList(head);

    head = ReverseList(head);
    printf("\n--- After reversing ---\n");
    PrintList(head);

    DestroyList(head);
    return 0;
}
