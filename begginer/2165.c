#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[501];
    int i;

    fgets(s, 501, stdin);

    for (i = 0; s[i] != '\n' && s[i] != '\0'; i++)
        ;

    if (i > 140)
        printf("MUTE\n");
    else
        printf("TWEET\n");

    return 0;
}