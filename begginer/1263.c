#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[5001], c1, c2;
    int i, cont = 0, canCont = 1;

    while (fgets(s, 5001, stdin))
    {
        c1 = s[0];
        if (c1 < 'a')
            c1 += 'a' - 'A';
        //printf("c1 %c.\n", c1);
        for (i = 0; s[i] != '\n' && s[i] != '\0'; i++)
        {
            if (s[i] == ' ')
            {
                c2 = s[i + 1];
                if (c2 < 'a')
                    c2 += 'a' - 'A';
                if (c1 == c2)
                {
                    if (canCont)
                    {
                        cont++;
                        canCont = 0;
                    }
                }
                else
                {
                    canCont = 1;
                }
                c1 = c2;
                c2 = '\0';
                i += 1;
            }
        }
        printf("%d\n", cont);
        cont = 0;
        canCont = 1;
    }

    return 0;
}