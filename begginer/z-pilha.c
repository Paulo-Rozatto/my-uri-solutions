#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dado;
    struct nodo *proximo;
} no;

void empilhar(no **topo, int valor)
{
    no *novo;

    novo = malloc(sizeof(no));
    novo->dado = valor;
    novo->proximo = *topo;
    *topo = novo;
}

void desempilhar(no **topo, int *valor)
{
    no *aux;

    if ((*topo) != NULL)
    {
        aux = *topo;
        *topo = aux->proximo;
        *valor = aux->dado;
        free(aux);
    }
}

void mostrar(no **topo)
{
    no *aux;
    if ((*topo != NULL))
    {
        aux = (*topo)->proximo;
        printf("%d ", (*topo)->dado);
        mostrar(&aux);
    }
}

int main()
{
    int ctrl = 0, valor;
    no *topo = NULL;

    while (ctrl != 4)
    {
        printf("1-Empilhar\n2-Desempilhar\n3-Mostrar\n4-Sair\n");
        scanf("%d", &ctrl);

        if (ctrl == 1)
        {
            printf("Digite um valor para empilhar: ");
            scanf("%d", &valor);

            empilhar(&topo, valor);
        }
        else if (ctrl == 2)
        {
            desempilhar(&topo, &valor);
        }
        else if (ctrl == 3)
        {
            mostrar(&topo);
            printf("\n\n");
        }
    }
    return 0;
}
