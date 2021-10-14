#include <stdio.h>
#include <stdlib.h>

int main()
{
    int meals[3], reqts[3], i, cont = 0;
    scanf("%d%d%d", &meals[0], &meals[1], &meals[2]);
    scanf("%d%d%d", &reqts[0], &reqts[1], &reqts[2]);

    for (i = 0; i < 3; i++)
    {
        if (reqts[i] > meals[i])
            cont += reqts[i] - meals[i];
    }
    printf("%d\n", cont);
    return 0;
}