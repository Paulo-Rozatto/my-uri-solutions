#include <stdio.h>
#include <stdlib.h>

#define TAM 12

int main()
{
    int line, i, j;
    float m[TAM][TAM];
    float resul = 0;
    char opt;

    scanf("%d", &line);
    scanf("%*c%c", &opt);

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            scanf("%f", &m[i][j]);
        }
    }

    for (j = 0; j < TAM; j++)
    {
        resul += m[line][j];
    }

    if (opt == 'M')
    {
        resul /= TAM;
    }

    printf("%.1f\n", resul);
    return 0;
}