#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    long long int id;
    long long int chave;
    struct No *prox;
} No;

void insere(No **tabela_hash, long long int id, long long int chave)
{
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->prox = NULL;

    if (tabela_hash[id] == NULL)
        tabela_hash[id] = novo_no;
    else
    {
        No *atual = tabela_hash[id];
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = novo_no;
    }
    tabela_hash[id]->chave += chave;
}

void retira(No **tabela_hash, long long int id, long long int chave)
{
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->prox = NULL;

    if (tabela_hash[id] == NULL)
        tabela_hash[id] = novo_no;
    else
    {
        No *atual = tabela_hash[id];
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = novo_no;
    }

    tabela_hash[id]->chave += chave;

    if (tabela_hash[id]->chave < 0)
        tabela_hash[id]->chave = 0;
}

void liberahash(No **tabela_hash, int m)
{
    for (int i = 0; i < m; i++)
    {
        No *no = tabela_hash[i];
        while (no != NULL)
        {
            No *temp = no;
            no = no->prox;
            free(temp);
        }
    }
}

int main()
{
    long long int n, idaux, chaveaux;
    long long int  somatotal = 0;
    scanf("%lld", &n);

    No **vetor = (No **)calloc(n, sizeof(No **));
    int vetid[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &idaux, &chaveaux);
        vetid[i] = idaux;
        if (chaveaux < 0)
            retira(vetor, idaux, chaveaux);
        else
            insere(vetor, idaux, chaveaux);
    }
    liberahash(vetor, n);
    free(vetor);
    printf("%lld", somatotal);

    return 0;
}