#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p1, p2;
    scanf("%d%d", &p1,&p2);
    if(!p1) printf("C");
    else if(p2) printf("A");
    else printf("B");
    printf("\n");
    return 0;
}