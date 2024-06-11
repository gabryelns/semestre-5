#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (1 << 20) // 2^20

typedef struct
{
    int colonia;
    char alimento[15];
    int entregue;
} item;

item hasht[MAX];

unsigned long hash(int colonia, char *alimento)
{
    unsigned long hash = colonia;
    int c;

    while ((c = *alimento++))
        hash = ((hash << 5) + hash) + c;

    return hash % MAX;
}

void insere(int colonia, char *alimento)
{
    unsigned long index = hash(colonia, alimento);
    while (hasht[index].entregue && !(hasht[index].colonia == colonia && strcmp(hasht[index].alimento, alimento) == 0))
        index = (index + 1) % MAX;

    if (!hasht[index].entregue)
    {
        hasht[index].colonia = colonia;
        strcpy(hasht[index].alimento, alimento);
        hasht[index].entregue = 1;
    }
}

int verifica(int colonia, char *alimento)
{
    unsigned long index = hash(colonia, alimento);
    while (hasht[index].entregue)
    {
        if (hasht[index].colonia == colonia && strcmp(hasht[index].alimento, alimento) == 0)
            return 1;
        index = (index + 1) % MAX;
    }
    return 0;
}

int main()
{
    int colonia;
    char alimento[15];

    while (scanf("%d %s", &colonia, alimento) != EOF)
    {
        if (verifica(colonia, alimento))
        {
            printf("%d\n", colonia);
        }
        else
        {
            insere(colonia, alimento);
        }
    }

    return 0;
}
