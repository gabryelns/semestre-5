#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2097152 // 2^21

struct Colonia
{
    int id;
    char alimento[11];
    struct Colonia *prox;
};

struct HashTable
{
    struct Colonia *lista[MAX];
};

int hash(char *alimento)
{
    int hash = 0;
    while (*alimento)
        hash += *alimento++;
    return hash % MAX;
}

void inicia(struct HashTable *ht)
{
    for (int i = 0; i < MAX; i++)
        ht->lista[i] = NULL;
}

void inserir(struct HashTable *ht, int id, char *alimento)
{
    int h = hash(alimento);
    struct Colonia *nova_colonia = (struct Colonia *)malloc(sizeof(struct Colonia));
    nova_colonia->id = id;
    strcpy(nova_colonia->alimento, alimento);
    nova_colonia->prox = ht->lista[h];
    ht->lista[h] = nova_colonia;
}

int buscar(struct HashTable *ht, char *alimento)
{
    int h = hash(alimento);
    struct Colonia *temp = ht->lista[h];
    while (temp != NULL)
    {
        if (strcmp(temp->alimento, alimento) == 0)
            return temp->id;
        temp = temp->prox;
    }
    return -1;
}

int main()
{
    struct HashTable ht;
    inicia(&ht);
    int colonia;
    char alimento[11];

    while (scanf("%d %s", &colonia, alimento) != EOF)
    {
        int id = buscar(&ht, alimento);
        if (id != -1)
            printf("%d\n", id);
        else
            inserir(&ht, colonia, alimento);
    }
    return 0;
}
