#include <stdio.h>
#include <stdlib.h>

double sqrt2(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1.5;
    return 1 + 1 / (1 + sqrt2(n - 1));
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%.10lf\n", sqrt2(n));
    return 0;
}