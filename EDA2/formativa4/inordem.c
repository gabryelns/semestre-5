#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz)
{

    if (raiz == NULL)
        return;

    no *aux = raiz;
    no *pilha[100];
    int topo = -1;

    while (1)
    {
        while (aux != NULL)
        {
            pilha[++topo] = aux;
            aux = aux->esq;
        }
        if (topo >= 0)
        {
            aux = pilha[topo--];
            printf("%d ", aux->dado);
            aux = aux->dir;
        }
        else
            break;
    }
    printf("\n");
}
