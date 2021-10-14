#include <stdio.h>
#include <stdlib.h>

int trib(int n)
{
    int resul;

    if (n < 2)
    {
        resul = 0;
    }
    else if (n < 3)
    {
        resul = 1;
    }
    else
        resul = trib(n - 1) + trib(n - 2) + trib(n - 3);

    return resul;
}

int main()
{
    printf("%d\n", trib(6));
    return 0;
}
