#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p, const void *q)
{
    int l = *(const int *)p;
    int r = *(const int *)q;
    return l - r;
}

int tri(int a, int b, int c)
{
    return a < (b + c) && b < (a + c) && c < (a + b);
}

int main()
{
    int v[4], i;

    for (i = 0; i < 4; i++)
    {
        scanf("%d ", &v[i]);
    }

    qsort(v, sizeof(v) / sizeof(int), sizeof(int), comparator);

    if (v[3] < (v[2] + v[1]) || v[2] < (v[0] + v[1]))
        printf("S\n");
    else
        printf("N\n");
    return 0;
}