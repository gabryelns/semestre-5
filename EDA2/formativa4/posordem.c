#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

void pos_ordem(no *raiz)
{

    if (raiz == NULL)
        return;

    no *aux = raiz;
    no *pilha[100];
    no *pilha1[100];
    int topo = -1;
    int topo1 = -1;

    pilha[++topo] = aux;

    while (topo >= 0)
    {
        aux = pilha[topo--];
        pilha1[++topo1] = aux;

        if (aux->esq != NULL)
            pilha[++topo] = aux->esq;

        if (aux->dir != NULL)
            pilha[++topo] = aux->dir;
    }

    while (topo1 >= 0)
    {
        aux = pilha1[topo1--];
        printf("%d ", aux->dado);
    }
    printf("\n");
}