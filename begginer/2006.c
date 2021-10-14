#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, i, ans, cont = 0;
    scanf("%d", &t);
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &ans);
        cont += ans == t;
    }
    printf("%d\n", cont);
    return 0;
}