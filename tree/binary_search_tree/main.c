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

    NODE *root2 = NULL;

    printf("\n--- Height NULL---\n");
    printf("Height: %d\n", GetHeight(root2));

    root2 = AddNode(root2, 4);
    printf("\n--- Height 4 ---\n");
    printf("Height: %d\n", GetHeight(root2));

    root2 = AddNode(root2, 2);
    printf("\n--- Height 4, 2 ---\n");
    printf("Height: %d\n", GetHeight(root2));

    root2 = AddNode(root2, 6);
    printf("\n--- Height 4, 2, 6 ---\n");
    printf("Height: %d\n", GetHeight(root2));

    root2 = AddNode(root2, 1);
    printf("\n--- Height 4, 2, 6, 1 ---\n");
    printf("Height: %d\n", GetHeight(root2));

    root2 = AddNode(root2, 5);
    printf("\n--- Height 4, 2, 6, 1, 5 ---\n");
    printf("Height: %d\n", GetHeight(root2));

    root2 = AddNode(root2, 3);
    printf("\n--- Height 4, 2, 6, 1, 5, 3 ---\n");
    printf("Height: %d\n", GetHeight(root2));

    root2 = AddNode(root2, 7);
    printf("\n--- Height 4, 2, 6, 1, 5, 3, 7 ---\n");
    printf("Height: %d\n", GetHeight(root2));

    printf("\n---Compare ---\n");
    bool result = CompareTrees(root, root2);
    printf("Are they same: %d\n", result);

    printf("\n--- Reversed ---\n");
    ReverseTree(root);
    PrintTree(root);
    DestroyTree(root);
    DestroyTree(root2);

    printf("\n---Compare ---\n");
    result = CompareTrees(root, root2);
    printf("Are they same: %d\n", result);
    return 0;
}
