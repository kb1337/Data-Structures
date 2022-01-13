#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dll.h"

int main(void)
{
    DLLI *head = NULL;

    for (int i = 1; i < 11; i++)
        head = AddItemToHead(head, i);

    printf("--- 10 item added to head ---\n");
    PrintList(head);

    for (int i = 1; i < 11; i++)
        head = AddItemToEnd(head, i);

    printf("--- 10 item added to end ---\n");
    PrintList(head);

    DestroyList(head);
    return 0;
}