#include <stdio.h>
#include <stdlib.h>

// Estrutura para os nós da lista ligada na tabela de hash
typedef struct No
{
    int chave;
    struct No *prox;
} No;

// Função hash para mapear chaves aos índices da tabela de hash
unsigned long funcao_hash(int chave, int m)
{
    return chave % m;
}

// Função para inserir uma chave na tabela de hash
void insere(No **tabela_hash, int m, int chave)
{
    unsigned long indice = funcao_hash(chave, m);
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->prox = NULL;

    // Se a lista estiver vazia, insere o novo nó diretamente
    if (tabela_hash[indice] == NULL)
        tabela_hash[indice] = novo_no;
    else
    {
        // Caso contrário, percorre a lista até encontrar o último nó
        No *atual = tabela_hash[indice];
        while (atual->prox != NULL)
            atual = atual->prox;
        // Insere o novo nó após o último nó existente
        atual->prox = novo_no;
    }
}

// Função para imprimir a tabela de hash
void imprime_tabela_hash(No **tabela_hash, int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ->", i);
        No *no = tabela_hash[i];
        while (no != NULL)
        {
            printf(" %d ->", no->chave);
            no = no->prox;
        }
        printf(" \\\n");
    }
}

// Função para liberar a memória alocada para a tabela de hash
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
    int num_casos;
    scanf("%d", &num_casos);

    for (int num_caso = 0; num_caso < num_casos; num_caso++)
    {
        int m, c;
        scanf("%d %d", &m, &c);

        No **tabela_hash = (No **)calloc(m, sizeof(No *));

        for (int i = 0; i < c; i++)
        {
            int chave;
            scanf("%d", &chave);
            insere(tabela_hash, m, chave);
        }

        if (num_caso > 0)
        {
            printf("\n");
        }

        imprime_tabela_hash(tabela_hash, m);

        liberahash(tabela_hash, m);
        free(tabela_hash);
    }

    return 0;
}
