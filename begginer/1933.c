#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maior, n;
    scanf("%d%d", &maior, &n);
    if (n > maior)
        maior = n;
    printf("%d\n", maior);
    return 0;
}