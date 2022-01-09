#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sll.h"

int main(void)
{
    SLLI *head = NULL;

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

    DestroyList(head);
    return 0;
}
