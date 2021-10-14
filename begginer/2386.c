#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, cont = 0;
    int tel, star;

    scanf("%d%d", &tel, &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &star);
        if (star * tel >= 40000000) cont++;
    }
    printf("%d\n",cont);
    return 0;
}