#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x;
    scanf("%d", &n);
    while (n > 0)
    {
        scanf("%d", &x);
        printf("%d\n", x % 2 != 0);
        n--;
    }
    return 0;
}