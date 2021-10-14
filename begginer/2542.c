#include <stdio.h>
#include <stdlib.h>

#define MAX_ATT 100
#define MAX_CARD 100

int main()
{
    int m[MAX_CARD][MAX_ATT], l[MAX_CARD][MAX_ATT];
    int att, m_cards, l_cards, drawn;
    int i, j;

    while (scanf("%d", &att) != EOF)
    {
        scanf("%d%d", &m_cards, &l_cards);
        for (i = 0; i < m_cards; i++)
        {
            for (j = 0; j < att; j++)
            {
                scanf("%d", &m[i][j]);
            }
        }
        for (i = 0; i < l_cards; i++)
        {
            for (j = 0; j < att; j++)
            {
                scanf("%d", &l[i][j]);
            }
        }
        scanf("%d%d", &m_cards, &l_cards);
        scanf("%d", &drawn);
        m_cards--;
        l_cards--;
        drawn--;
        if (m[m_cards][drawn] > l[l_cards][drawn])
        {
            printf("Marcos\n");
        }
        else if (m[m_cards][drawn] < l[l_cards][drawn])
        {
            printf("Leonardo\n");
        }
        else
        {
            printf("Empate\n");
        }
    }

    return 0;
}