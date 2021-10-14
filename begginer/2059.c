#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p, j1, j2, r, a;

    scanf("%d%d%d%d%d", &p, &j1, &j2, &r, &a);
    j1 += j2;

    if (r)
    {

        if (a)
        {
            printf("Jogador 2 ganha!\n");
            return 0;
        }
        printf("Jogador 1 ganha!\n");
        return 0;
    }
    else
    {
        if (a)
        {
            printf("Jogador 1 ganha!\n");
            return 0;
        }
    }
    if ((p % 2 != 0 && j1 % 2 == 0) || (p % 2 == 0 && j1 % 2 != 0))
        printf("Jogador 1 ganha!\n");
    else
        printf("Jogador 2 ganha!\n");
    return 0;
}