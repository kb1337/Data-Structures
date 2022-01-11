#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void)
{
    NODE *root = NULL;

    root = AddNode(root, 4);
    root = AddNode(root, 2);
    root = AddNode(root, 6);
    root = AddNode(root, 1);
    root = AddNode(root, 5);
    root = AddNode(root, 3);
    root = AddNode(root, 7);

    PrintTree(root);

    int maxValue = FindMaxValue(root);
    printf("\nMax Value: %d\n", maxValue);

    int target = 5;

    printf("\nSearch %d", target);
    NODE *res1 = FindNode(root, target);
    if (NULL != res1)
        printf("\n%d found\n", res1->data);

    target = 45;
    printf("\nSearch %d", target);
    NODE *res2 = FindNode(root, target);
    if (NULL != res2)
        printf("\n%d found\n", res2->data);
    else
        printf("\n%d not found\n", target);

    printf("\n--- Reversed ---\n");
    ReverseTree(root);
    PrintTree(root);

    DestroyTree(root);

    return 0;
}
