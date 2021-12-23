#include <stdio.h>

#define ARR_SIZE 10

void printArray(int *pArr, int size);
void printArrayReverse(int *pArr, int size);
void printArrayRecursive(int *pArr, int size);
void printArrayRecursiveReverse(int *pArr, int size);

int array[] = {9, 13, 10, 95, 28, 50, 0, 75, 5, 23};

int main()
{
    printf("----- Iterative -----\n");
    printArray(array, ARR_SIZE);
    printf("----- Recursive -----\n");
    printArrayRecursive(array, ARR_SIZE);

    printf("----- Iterative Reverse -----\n");
    printArrayReverse(array, ARR_SIZE);
    printf("----- Recursive Reverse -----\n");
    printArrayRecursiveReverse(array, ARR_SIZE);

    return 0;
}

void printArray(int *pArr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Arr[%d]: %d\n", i, pArr[i]);
    }
}

void printArrayReverse(int *pArr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("Arr[%d]: %d\n", i, pArr[i]);
    }
}

void printArrayRecursive(int *pArr, int size)
{
    if (size <= 0)
        return;

    printArrayRecursive(pArr, size - 1);
    printf("Arr[%d]: %d\n", size - 1, pArr[size - 1]);
}

void printArrayRecursiveReverse(int *pArr, int size)
{
    if (size <= 0)
        return;

    printf("Arr[%d]: %d\n", size - 1, pArr[size - 1]);
    printArrayRecursiveReverse(pArr, size - 1);
}
