#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cur, boi, bot, map, lar;
    scanf("%d%d%d%d%d",&cur,&boi,&bot,&map,&lar);
    cur *= 300;
    boi *= 1500;
    bot *= 600;
    map *= 1000;
    lar *= 150;

    printf("%d\n", 225 + cur + boi + bot + map + lar);
    return 0;
}