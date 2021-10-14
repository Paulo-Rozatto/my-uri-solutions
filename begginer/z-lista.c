#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dado;
    struct nodo *proximo;
} no;

int adLista(no **lista, int valor)
{
    int erro = 0, flag = 1;
    no *novo, *p;

    if ((novo = malloc(sizeof(novo))) == NULL)
        erro = 1;
    else
    {
        novo->dado = valor;

        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }
        else if ((*lista)->dado == novo->dado)
        {
            novo->proximo = *lista;
            *lista = novo;
        }
        else
        {
            p = *lista;

            while (flag)
            {
                if (p->proximo == NULL)
                    flag = 0;
                else if (p->proximo->dado >= valor)
                    flag = 0;
                else
                    p = p->proximo;
            }
            novo->proximo = p->proximo;
            p->proximo = novo;
        }
    }

    return erro;
}

int remLista(no **lista, int valor)
{
    no *p, *aux;
    int erro = 0, flag = 1;

    if (*lista == NULL)
        erro = 1;
    else if ((*lista)->dado == valor)
    {
        aux = *lista;
        *lista = aux->proximo;
        free(aux);
    }
    else
    {
        p = *lista;

        while (flag)
        {
            if (p->proximo == NULL)
            {
                erro = 2;
                flag = 0;
            }
            else if (p->proximo->dado == valor)
            {
                flag = 0;
            }
            else
            {
                p = p->proximo;
            }
        }

        if (erro == 0)
        {
            aux = p->proximo;
            p->proximo = aux->proximo;
            free(aux);
        }
    }
    return erro;
}

void mostrar(no **lista)
{
    no *aux;

    if ((*lista != NULL))
    {
        printf("%d ", (*lista)->dado);
        aux = (*lista)->proximo;
        mostrar(&aux);
    }
}

int main()
{
    int ctrl = 0, valor;
    no *lista = NULL;

    while (ctrl != 4)
    {
        printf("1-Adcionar\n2-Remover\n3-Mostrar\n4-Sair\n");
        scanf("%d", &ctrl);

        if (ctrl == 1)
        {
            printf("Digite um valor para inserir: ");
            scanf("%d", &valor);

            adLista(&lista, valor);
        }
        else if (ctrl == 2)
        {
            printf("Digite um valor para remover: ");
            scanf("%d", &valor);
            remLista(&lista, valor);
        }
        else if (ctrl == 3)
        {
            mostrar(&lista);
            printf("\n\n");
        }
    }
    return 0;
}