#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

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

NODE *AddNode(NODE *tree, int data)
{
    if (NULL == tree)
    {
        NODE *newNode = AllocateMemory(sizeof(NODE), "AddNode", EXIT_PROGRAM);
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }
    else
    {
        if (tree->data < data)
        {
            tree->right = AddNode(tree->right, data);
        }
        else
        {
            tree->left = AddNode(tree->left, data);
        }
        return tree;
    }
}

void PrintTree(NODE *root)
{
    if (NULL == root)
        return;

    PrintTree(root->left);
    printf("Data: %d\n", root->data);
    PrintTree(root->right);
}

void ReverseTree(NODE *tree)
{
    if (NULL == tree)
        return;

    NODE *tmp = tree->right;
    tree->right = tree->left;
    tree->left = tmp;

    ReverseTree(tree->left);
    ReverseTree(tree->right);
}

NODE *FindNode(NODE *tree, int data)
{
    if (NULL == tree || tree->data == data)
        return tree;

    if (tree->data < data)
        return FindNode(tree->right, data);

    return FindNode(tree->left, data);
}

int FindMaxValue(NODE *tree)
{

    while (tree->right != NULL)
        tree = tree->right;

    return tree->data;
}

bool CompareTrees(NODE *a, NODE *b)
{
    // Both empty
    if (NULL == a && NULL == b)
        return true;

    // Both non-empty
    if (NULL != a && NULL != b)
    {
        return (
            a->data == b->data &&
            CompareTrees(a->left, b->left) &&
            CompareTrees(a->right, b->right));
    }

    // one empty, one not
    return false;
}

void DestroyTree(NODE *tree)
{
    if (NULL == tree)
        return;

    DestroyTree(tree->left);
    DestroyTree(tree->right);
    free(tree);
}
