#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[51];
    int i, n = 0;

    while (fgets(s, 51, stdin))
    {
        for (i = 0; s[i] != '\n' && s[i] != '\0'; i++)
        {
            if (!n)
            {
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    s[i] += 'A' - 'a';
                }
                if (s[i] != ' ')
                    n = 1;
            }
            else
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    s[i] -= 'A' - 'a';
                }
                if (s[i] != ' ')
                    n = 0;
            }
        }
        printf("%s", s);
        n = 0;
    }
    return 0;
}