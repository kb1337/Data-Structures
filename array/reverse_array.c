#include <stdio.h>

#define ARR_SIZE 10
int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void printArray(int *pArr, int size);
void reverseArray(int *pArr, int size);

int main()
{
    printf("----- Array -----\n");
    printArray(array, ARR_SIZE);
    reverseArray(array, ARR_SIZE);
    printf("----- Reversed Array -----\n");
    printArray(array, ARR_SIZE);
}

void reverseArray(int *pArr, int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        int temp = pArr[i];
        pArr[i] = pArr[size - i - 1];
        pArr[size - i - 1] = temp;
    }
}

void printArray(int *pArr, int size)
{
    if (size <= 0)
        return;
    printArray(pArr, size - 1);
    printf("Arr[%d]: %d\n", size - 1, pArr[size - 1]);
}
