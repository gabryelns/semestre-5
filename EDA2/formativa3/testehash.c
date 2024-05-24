#include <stdio.h>
#include <stdlib.h>

// Estrutura para os nós da lista ligada na tabela de hash
typedef struct Node
{
    int key;
    struct Node *next;
} Node;

// Função hash para mapear chaves aos índices da tabela de hash
unsigned long hash_function(int key, int m)
{
    return key % m;
}

// Função para inserir uma chave na tabela de hash
void insert(Node **hash_table, int m, int key)
{
    unsigned long index = hash_function(key, m);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;

    // Se a lista estiver vazia, insere o novo nó diretamente
    if (hash_table[index] == NULL)
        hash_table[index] = new_node;
    else
    {
        // Caso contrário, percorre a lista até encontrar o último nó
        Node *current = hash_table[index];
        while (current->next != NULL)
            current = current->next;
        // Insere o novo nó após o último nó existente
        current->next = new_node;
    }
}

// Função para imprimir a tabela de hash
void print_hash_table(Node **hash_table, int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ->", i);
        Node *node = hash_table[i];
        while (node != NULL)
        {
            printf(" %d ->", node->key);
            node = node->next;
        }
        printf(" \\\n");
    }
}

// Função para liberar a memória alocada para a tabela de hash
void free_hash_table(Node **hash_table, int m)
{
    for (int i = 0; i < m; i++)
    {
        Node *node = hash_table[i];
        while (node != NULL)
        {
            Node *temp = node;
            node = node->next;
            free(temp);
        }
    }
}

int main()
{
    int num_cases;
    scanf("%d", &num_cases);

    for (int case_num = 0; case_num < num_cases; case_num++)
    {
        int m, c;
        scanf("%d %d", &m, &c);

        Node **hash_table = (Node **)calloc(m, sizeof(Node *));

        for (int i = 0; i < c; i++)
        {
            int key;
            scanf("%d", &key);
            insert(hash_table, m, key);
        }

        if (case_num > 0)
        {
            printf("\n");
        }

        print_hash_table(hash_table, m);

        free_hash_table(hash_table, m);
        free(hash_table);
    }

    return 0;
}
