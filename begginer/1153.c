#include <stdio.h>
#include <stdlib.h>

int fat(int n)
{
    return n > 1? n * fat(n-1): n;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n",fat(n));
    return 0;
}