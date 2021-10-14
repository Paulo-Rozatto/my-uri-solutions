#include <stdio.h>
#include <stdlib.h>

#define TAM 12

int main()
{
    int i, j, n = 0;
    float m[TAM][TAM];
    float resul = 0;
    char opt;

    scanf("%c", &opt);

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            scanf("%f", &m[i][j]);
        }
    }

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if(j > i)
            {
                resul += m[i][j];
                n++;
            }
        }
    }

    if (opt == 'M')
    {
        resul /= n;
    }

    printf("%.1f\n", resul);
    return 0;
}