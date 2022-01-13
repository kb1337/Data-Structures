#ifndef dll_h
#define dll_h

typedef struct DLLI
{
    int data;
    struct DLLI *prev;
    struct DLLI *next;
} DLLI;

void *AllocateMemory(int sizeBytes, const char *stdErr, bool bExit);

DLLI *AddItemToEnd(DLLI *head, int data);
DLLI *AddItemToHead(DLLI *head, int data);

DLLI *AddItemInOrder(DLLI *head, int data);

void PrintList(DLLI *head);
void PrintList_Recursive(DLLI *head);

void PrintListReverse(DLLI *head);

DLLI *DeleteItemFromList(DLLI *head, int toDel);
DLLI *DeleteItemFromList_Recursive(DLLI *head, int toDel);

void DestroyList(DLLI *head);

DLLI *ReverseList(DLLI *head);

#endif