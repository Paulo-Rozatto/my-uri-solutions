#include <stdio.h>

int main()
{
    int nbad, nlat, ncop, copQuebrados = 0, i;
    scanf("%d", &nbad);
    for ( i = 0; i < nbad; i++)
    {
        scanf("%d %d", &nlat,&ncop);
        if(nlat > ncop)
            copQuebrados += ncop;
    }
    printf("%d\n", copQuebrados);
    
    return 0;
}