#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", (int) log2(n));
    }
    
    return 0;
}