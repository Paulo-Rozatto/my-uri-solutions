#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p1,c1,p2,c2;
    scanf("%d%d%d%d", &p1, &c1, &p2, &c2);
    p1 *= c1;
    p2 *= c2;
    if(p1 == p2) printf("0");
    else if(p1 > p2) printf("-1");
    else printf("1");
    printf("\n");
    return 0;
}