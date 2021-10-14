#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[5], i, cont;
    for (i = 0; i < 5; i++)
        scanf("%d", &v[i]);
    for (i = 0; i < 5; i++)
        if(v[i] % 2 == 0) cont++;
    
    printf("%d valores pares\n", cont);
    return 0;
}