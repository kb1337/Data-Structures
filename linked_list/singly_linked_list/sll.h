#ifndef sll_h
#define sll_h

typedef struct SLLI
{
    int data;
    struct SLLI *next;
} SLLI;

void *AllocateMemory(int sizeBytes, const char *stdErr, bool bExit);

SLLI *AddItemToEnd(SLLI *head, int data);
SLLI *AddItemToHead(SLLI *head, int data);

void PrintList(SLLI *head);
void PrintList_Recursive(SLLI *head);

void PrintListReverse(SLLI *head);

void DestroyList(SLLI *head);

SLLI *DeleteItemFromList(SLLI *head, int toDel);
SLLI *DeleteItemFromList_Recursive(SLLI *head, int toDel);

#endif
