#include <stdio.h>
#include <stdlib.h>

#define TAM 2

int main()
{
    int a[TAM][TAM] = {0,1,2,3}, b[TAM][TAM] = {0,1,2,3}, c[TAM][TAM] = {0};
    int n, p, q, r, s, x, y;
    int i, j, k, ci, cj;

    scanf("%d", &n);
    scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &x, &y);
    scanf("%d%d", &ci, &cj);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = (p * (1-1+i) + q * (j+1-1)) * x;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[i][j] = (r * (i+1-1) + q * (1-1+j)) * y;
        }
    }


    for (i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            for(k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ",c[i][j]);
        }
        printf("\n"); 
    }
    
    return 0;
}