#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 2

int main()
{
    int A[TAM][TAM], B[TAM][TAM];
    int n, p, q, r, s, x, y;
    int i, j, a, b, ci, cj, c = 0;

    scanf("%d", &n);
    scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &x, &y);
    scanf("%d%d", &ci, &cj);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a = (p * ci + q * i) * x;
            b = (r * i + q * cj) * y;
            c = c + (a * b);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a = (p * i + q * j) * x;
            printf("%d ", a);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            b = (r * i + q * j) * y;
            printf("%d ", b);
        }
        printf("\n");
    }

    printf("%d\n", c);

    return 0;
}