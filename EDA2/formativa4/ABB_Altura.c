#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;

int altura(no *r)
{
    if (r == NULL)
        return 0;

    else
    {
        int esq = altura(r->esq);
        int dir = altura(r->dir);

        if (esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}
