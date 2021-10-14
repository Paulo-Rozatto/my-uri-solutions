#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, time, vm, total = 0;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &time, &vm);
        total += time * vm;
    }
    printf("%d\n", total);
    return 0;
}