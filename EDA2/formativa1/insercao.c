#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x)
{
    celula *novo = malloc(sizeof(celula));
    novo->dado = x; 
    novo->prox = le->prox;

    le->prox = novo;
}

void insere_antes(celula *le, int x, int y)
{
    celula *nova = malloc(sizeof(celula));  
    nova->dado = x;

    celula *anterior = le, *atual = le->prox;

    while (atual != NULL && atual->dado != y)
    {
        anterior = atual;
        atual = anterior->prox;
    }

    nova->prox = atual;
    anterior->prox = nova;
}
