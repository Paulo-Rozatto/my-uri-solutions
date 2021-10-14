#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x, y;
    while (scanf("%lld%lld", &x, &y) != EOF)
    {
        printf("%lld\n", x ^ y);
    }
    return 0;
}