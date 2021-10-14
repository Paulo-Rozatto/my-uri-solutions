#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, total = 0, i;
    for(i = 0; i < 4; i++)
    {
        scanf("%d", &t);
        total += t;
    }
    printf("%d\n", total - 3);
    return 0;
}