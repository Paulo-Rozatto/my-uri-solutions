#include <stdio.h>

int main()
{
    int time, speed;
    scanf("%d%d", &time, &speed);
    printf("%.3f\n", (speed * time) / (float) 12);
    return 0;
}