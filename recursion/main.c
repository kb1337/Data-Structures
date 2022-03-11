#include <stdio.h>
#include <stdlib.h>

// F(N) = F(N-1) + F(N-2)
// F(0) - 1, F(1) = 1

/*
fib(4)
    fib(3)
        fib(2)
            fib(1)
            fib(0)
        fib(1)
    fib(2)
        fib(1)
        fib(0)
*/

int cnt;

int fib_tree(int N, int depth)
{
    for (int i = 0; i < depth; i++)
        printf("--");
    printf("fib(%d)\n", N);

    cnt++;

    if (N <= 1)
        return 1;

    return fib_tree(N - 1, depth + 1) + fib_tree(N - 2, depth + 1);
}

int fib_seq(int N)
{
    int x = 1;
    int y = 1;

    printf("%d ", x);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", y);

        int tmp = x;
        x = y;
        y = tmp + y;
    }
    printf("\n");

    return x;
}

int main()
{
    int N = 5;
    cnt = 0;
    int f = fib_tree(N, 0);
    printf("fib(%d) = %d, # of calls = %d\n", N, f, cnt);

    printf("\n\n");

    printf("fib(%d) = %d\n", N, fib_seq(N));

    return 0;
}
