# Array

<details><summary>Array size</summary>
<p>

```c
int array[] = {1, 2, 3, 4, 5};
int size = sizeof(array) / sizeof(int);
printf("%d\n", size);
```

Output:
```
5
```
</p>
</details>

<details><summary>Print an Array</summary>
<p>

Print an Array `in order`. (Iterative approach)

```c
void printArray(int *pArr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Arr[%d]: %d\n", i, pArr[i]);
    }
}
```

Print an Array `in reverse order`. (Iterative approach)

```c
void printArrayReverse(int *pArr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("Arr[%d]: %d\n", i, pArr[i]);
    }
}
```

Print an Array `in order`. (Recursive approach)

```c
void printArrayRecursive(int *pArr, int size)
{
    if (size <= 0)
        return;

    printArrayRecursive(pArr, size - 1);
    printf("Arr[%d]: %d\n", size - 1, pArr[size - 1]);
}
```

Print an Array `in reverse order`. (Recursive approach)

```c
void printArrayRecursiveReverse(int *pArr, int size)
{
    if (size <= 0)
        return;

    printf("Arr[%d]: %d\n", size - 1, pArr[size - 1]);
    printArrayRecursiveReverse(pArr, size - 1);
}
```
</p>
</details>

<details><summary>Reverse an Array</summary>
<p>

```c
void reverseArray(int *pArr, int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        int temp = pArr[i];
        pArr[i] = pArr[size - i - 1];
        pArr[size - i - 1] = temp;
    }
}
```
</p>
</details>
