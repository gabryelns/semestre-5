#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No *novoNo(int dado)
{
    No *no = (No *)malloc(sizeof(No));
    no->dado = dado;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

int altura(No *no)
{
    if (no == NULL)
        return 0;
    int altura_esquerda = altura(no->esq);
    int altura_direita = altura(no->dir);
    return 1 + ((altura_esquerda > altura_direita) ? altura_esquerda : altura_direita);
}

int estaBalanceada(No *raiz)
{
    if (raiz == NULL)
        return 1;
    int altura_esquerda = altura(raiz->esq);
    int altura_direita = altura(raiz->dir);
    if (abs(altura_esquerda - altura_direita) <= 1 && estaBalanceada(raiz->esq) && estaBalanceada(raiz->dir))
        return 1;
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);

    int *pai = (int *)malloc((N - 1) * sizeof(int));
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d", &pai[i]);
    }

    No **nos = (No **)malloc(N * sizeof(No *));
    for (int i = 0; i < N; i++)
    {
        nos[i] = novoNo(i + 1);
    }

    No *raiz = nos[0];
    for (int i = 1; i < N; i++)
    {
        if (nos[pai[i - 1] - 1]->esq == NULL)
            nos[pai[i - 1] - 1]->esq = nos[i];
        else
            nos[pai[i - 1] - 1]->dir = nos[i];
    }

    if (estaBalanceada(raiz))
        printf("Sim\n");
    else
        printf("Nao\n");

    free(pai);
    free(nos);

    return 0;
}
