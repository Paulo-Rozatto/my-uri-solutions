#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, d1, n2, d2, control;
    char op;

    scanf("%d", &control);

    while (control--)
    {
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);

        if (op == '+')
        {
            n1 = n1 * d2 + n2 * d1;
            d1 = d1 * d2;
        }
        else if (op == '-')
        {
            n1 = n1 * d2 - n2 * d1;
            d1 = d1 * d2;
        }
        else if(op == '*')
        {
            n1 = n1 * n2;
            d1 = d1 * d2;
        }
        else if (op == '/')
        {
            n1 = n1 * d2;
            d1 = d1 * n2;
        }

        printf("%d/%d = ", n1, d1);

        d2 = n1 > d1 ? n1 : d1;

        while (d2 > 1)
        {
            if( n1 % d2 == 0 && d1 % d2 == 0)
            {
                n1 /= d2;
                d1 /= d2;
            }
            d2--;
        }

        printf("%d/%d\n", n1, d1);
        
    }
    
    return 0;
}