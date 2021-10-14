#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t, n;
    long int sum;
    scanf("%d", &t);
    while (t--)
    {
        sum = 0; 
        scanf("%d", &n);
        while (n--)
        {
            sum += pow(2, n);
        }
        printf("%ld\n", sum);  
    }
    return 0;
}