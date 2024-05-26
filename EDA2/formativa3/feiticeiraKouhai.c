#include <stdio.h>
#include <stdlib.h>

#define MAX (524287)

typedef struct Item
{
    long long id;
    long long qtd;
    struct Item *prox;
} Item;

Item *tabela_hash[MAX] = {NULL};

long funcaohash(long long id)
{
    return (id % MAX);
}

Item *encontrar_item(long long id)
{
    unsigned long indice = funcaohash(id);
    Item *atual = tabela_hash[indice];
    while (atual != NULL)
    {
        if (atual->id == id)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

void insere(long long id, long long qtd)
{
    unsigned long indice = funcaohash(id);
    Item *item_existente = encontrar_item(id);

    if (item_existente != NULL)
    {
        item_existente->qtd += qtd;
        if (item_existente->qtd < 0)
        {
            item_existente->qtd = 0;
        }
    }
    else
    {
        if (qtd > 0)
        {
            Item *novo_item = (Item *)malloc(sizeof(Item));
            novo_item->id = id;
            novo_item->qtd = qtd;
            novo_item->prox = tabela_hash[indice];
            tabela_hash[indice] = novo_item;
        }
    }
}

void liberahash()
{
    for (int i = 0; i < MAX; i++)
    {
        Item *atual = tabela_hash[i];
        while (atual != NULL)
        {
            Item *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        tabela_hash[i] = NULL;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    long long id, qtd;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &id, &qtd);
        id += 536870912;
        if (qtd != 0)
            insere(id, qtd);
    }

    long long qtd_total = 0;

    for (int i = 0; i < MAX; i++)
    {
        Item *atual = tabela_hash[i];
        while (atual != NULL)
        {
            qtd_total += atual->qtd;
            atual = atual->prox;
        }
    }

    printf("%lld\n", qtd_total);

    liberahash();

    return 0;
}
