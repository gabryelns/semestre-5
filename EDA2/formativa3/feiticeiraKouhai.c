#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int id;
    int chave;
    struct No *prox;
} No;

void insere(No **tabela_hash, int id, int chave)
{
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->prox = NULL;

    // Se a lista estiver vazia, insere o novo nó diretamente
    if (tabela_hash[id] == NULL)
        tabela_hash[id] = novo_no;
    else
    {
        // Caso contrário, percorre a lista até encontrar o último nó
        No *atual = tabela_hash[id];
        while (atual->prox != NULL)
            atual = atual->prox;
        // Insere o novo nó após o último nó existente
        atual->prox = novo_no;
    }
    tabela_hash[id]->chave += chave;
}

void retira(No **tabela_hash, int id, int chave)
{
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->prox = NULL;

    // Se a lista estiver vazia, insere o novo nó diretamente
    if (tabela_hash[id] == NULL)
        tabela_hash[id] = novo_no;
    else
    {
        // Caso contrário, percorre a lista até encontrar o último nó
        No *atual = tabela_hash[id];
        while (atual->prox != NULL)
            atual = atual->prox;
        // Insere o novo nó após o último nó existente
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
    int n, somatotal = 0, idaux, chaveaux;

    scanf("%d", &n);

    No **vetor = (No **)calloc(n, sizeof(No **));
    int vetid[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &idaux, &chaveaux);
        vetid[i] = idaux;
        if (chaveaux < 0)
            retira(vetor, idaux, chaveaux);
        else
            insere(vetor, idaux, chaveaux);
    }
    liberahash(vetor, n);
    free(vetor);
    printf("%d", somatotal);

    return 0;
}