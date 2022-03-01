# Binary Search Tree
Structure

```c
typedef struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
} NODE;
```
<details><summary>Allocate Memory</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>Add node</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>Print the tree</summary>
<p>

```c
void PrintTree(NODE *root)
{
    if (NULL == root)
        return;

    PrintTree(root->left);
    printf("Data: %d\n", root->data);
    PrintTree(root->right);
}
```
</p>
</details>

<details><summary>Compare two trees</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>Reverse the tree</summary>
<p>

```c
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
```
</p>
</details>

<details><summary>Height of the tree</summary>
<p>

```c
int GetHeight(NODE *tree)
{
    if (NULL == tree)
        return -1;

    int left = GetHeight(tree->left);
    int right = GetHeight(tree->right);

    if (left < right)
        return right + 1;
    else
        return left + 1;
}
```
</p>
</details>

<details><summary>Find node</summary>
<p>

```c
NODE *FindNode(NODE *tree, int data)
{
    if (NULL == tree || tree->data == data)
        return tree;

    if (tree->data < data)
        return FindNode(tree->right, data);

    return FindNode(tree->left, data);
}
```
</p>
</details>

<details><summary>Find the maximum value</summary>
<p>

```c
int FindMaxValue(NODE *tree)
{
    while (tree->right != NULL)
        tree = tree->right;

    return tree->data;
}
```
</p>
</details>

<details><summary>Destroy the tree</summary>
<p>

```c
void DestroyTree(NODE *tree)
{
    if (NULL == tree)
        return;

    DestroyTree(tree->left);
    DestroyTree(tree->right);
    free(tree);
}
```
</p>
</details>
