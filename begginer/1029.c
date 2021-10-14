#include <stdio.h>
#include <stdlib.h>

int calls;

int fib(int n)
{
    calls++;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int t, n;

    scanf("%d", &t);

    while (t--)
    {
        calls = -1;
        scanf("%d", &n);
        printf("fib(%d) = %d calls = %d\n", n, calls, fib(n));
    }

    return 0;
}