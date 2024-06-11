#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;

no *inserir(no *r, int x)
{
    if (r == NULL)
    {
        no *novo_no = (no *)malloc(sizeof(no));
        novo_no->chave = x;
        novo_no->esq = novo_no->dir = NULL;
        return novo_no;
    }
    if (x < r->chave)
        r->esq = inserir(r->esq, x);

    else if (x > r->chave)
        r->dir = inserir(r->dir, x);

    return r;
}

void inordem(no *r, int *vetor, int *index, int t)
{
    if (r != NULL && *index < t)
    {
        inordem(r->esq, vetor, index, t);
        if (*index < t)
        {
            vetor[*index] = r->chave;
            (*index)++;
        }
        inordem(r->dir, vetor, index, t);
    }
}

void imprime(no *r, int t)
{
    int *vetor = (int *)malloc(t * sizeof(int));
    int index = 0;
    inordem(r, vetor, &index, t);
    for (int i = 0; i < t; i++)
    {
        if (i > 0)
            printf(" ");

        printf("%d", vetor[i]);
    }
    printf("\n");
    free(vetor);
}

int main()
{
    int id, placa;
    no *raiz = NULL;

    while (scanf("%d %d", &id, &placa) != EOF)
    {
        if (id == 1)
            raiz = inserir(raiz, placa);

        else if (id == 2)
            imprime(raiz, placa);
    }
    return 0;
}
