#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(!n) printf("E");
    else if(n <36) printf("D");
    else if(n < 61) printf("C");
    else if(n < 86) printf("B");
    else printf("A");
    printf("\n");
    return 0;
}