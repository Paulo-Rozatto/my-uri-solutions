#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, sum = 0;
    scanf("%d%d", &x, &y);
    if (x < y)
    {
        for (x; x <= y; x++)
        {
            if (x % 13)
                sum += x;
        }
    }
    else
    {
        for (y; y <= x; y++)
        {
            if (y % 13)
                sum += y;
        }
    }
    printf("%d\n", sum);
    return 0;
}