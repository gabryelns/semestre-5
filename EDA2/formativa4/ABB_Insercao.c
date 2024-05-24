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
    {
        r->esq = inserir(r->esq, x);
    }
    else if (x > r->chave)
        r->dir = inserir(r->dir, x);

    return r;
}