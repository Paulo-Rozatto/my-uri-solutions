#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dado;
    struct nodo *proximo;
} no;

int enfileirar(no **inicio, no **fim, int valor)
{
    no *novo;
    int erro = 0;

    novo = malloc(sizeof(no));

    if (novo == NULL)
        erro = 1;
    else
    {
        novo->dado = valor;

        if (*fim == NULL)
        {
            (*fim) = novo;
            (*inicio) = novo;
        }
        else
        {
            (*fim)->proximo = novo;
            *fim = novo;
        }
    }
    return erro;
}

int desenfileirar(no **inicio, no **fim, int *valor)
{
    int erro = 0;
    no *aux;

    if (*inicio == NULL)
        erro = 1;
    else
    {
        aux = *inicio;
        *valor = aux->dado;
        *inicio = aux->proximo;

        if (*inicio == NULL)
            *fim = NULL;

        free(aux);
    }
    return erro;
}

void mostrar(no **inicio, no **fim)
{
    no *aux;
    if (*inicio != NULL)
    {
        printf("%d ", (*inicio)->dado);

        aux = (*inicio)->proximo;

        if ((*inicio) != (*fim))
            mostrar(&aux, &fim);
    }
}

int main()
{
    int ctrl = 0, valor;
    no *inicio = NULL, *fim = NULL;

    while (ctrl != 4)
    {
        printf("Digite:\n");
        printf("1-Enfileirar\n2-Desenfileirar\n3-Mostrar\n4-Sair\n");
        scanf("%d", &ctrl);
        system("clear||cls");

        if (ctrl == 1)
        {
            printf("Digite um valor para enfileirar: ");
            scanf("%d", &valor);

            if (enfileirar(&inicio, &fim, valor) == 0)
                printf("Colocado na fila com sucesso\n");
            else
                printf("Erro! Não foi possível alocar memória!\n");
        }
        else if (ctrl == 2)
        {
            system("clear||cls");
            if (desenfileirar(&inicio, &fim, &valor) == 0)
                printf("Valor removido da fila: %d\n", valor);
            else
                printf("Fila vazia!\n");
        }
        else if (ctrl == 3)
        {
            printf("Valores enfileirados: ");
            mostrar(&inicio, &fim);
            printf("\n");
        }
        else if (ctrl != 4)
            printf("Valor Inválido\n\n");
    }
    return 0;
}
