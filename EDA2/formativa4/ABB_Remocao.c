#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;

no *remover(no *r, int x)
{
    if (r == NULL)
        return NULL;

    if (x < r->chave) {
        r->esq = remover(r->esq, x);
    } else if (x > r->chave) {
        r->dir = remover(r->dir, x);
    } else {
        if (r->esq == NULL) {
            no* temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no* temp = r->esq;
            free(r);
            return temp;
        } else {
            no* p = r;
            no* q = r->esq;
            while (q->dir != NULL) {
                p = q;
                q = q->dir;
            }
            r->chave = q->chave;
            if (p != r)
                p->dir = q->esq;
            else
                p->esq = q->esq;
            free(q);
        }
    }
    return r;
}