#ifndef bst_h
#define bst_h

#include <stdbool.h>

#define EXIT_PROGRAM true
#define DO_NOT_EXIT_PROGRAM false

typedef struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
} NODE;

void *AllocateMemory(int sizeBytes, const char *strErr, bool bExit);

NODE *AddNode(NODE *tree, int data);

void PrintTree(NODE *tree);

void ReverseTree(NODE *tree);

NODE *FindNode(NODE *tree, int data);
int FindMaxValue(NODE *tree);

bool CompareTrees(NODE *a, NODE *b);

void DestroyTree(NODE *tree);

#endif
