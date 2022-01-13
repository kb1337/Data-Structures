#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dll.h"

int main(void)
{
    DLLI *head = NULL;

    printf("--- 10 item added to head ---\n");
    for (int i = 1; i < 11; i++)
        head = AddItemToHead(head, i);
    PrintList(head);

    printf("---  print in reverse order ---\n");
    PrintListReverse(head);

    printf("--- 5 item added to end ---\n");
    for (int i = 0; i < 5; i++)
        head = AddItemToEnd(head, i);
    PrintList(head);

    printf("---  print in reverse order ---\n");
    PrintListReverse(head);

    printf("--- print in reverse order (recursive)---\n");
    PrintListReverse_Recursive(head);

    printf("--- list reversed ---\n");
    head = ReverseList(head);
    PrintList_Recursive(head);

    DestroyList(head);
    return 0;
}
