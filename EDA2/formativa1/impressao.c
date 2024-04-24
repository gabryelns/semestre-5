#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le){

    celula *atual= le->prox;
    while(atual !=NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    
    printf("NULL\n");
}
void imprime_rec (celula *le){

    celula *atual = le->prox;
    if(atual== NULL) {
    printf("NULL\n");
    return;
    }
    printf("%d -> ", atual->dado);
    imprime_rec(atual);
}