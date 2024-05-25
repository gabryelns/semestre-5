#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10007

typedef struct Par
{
    char chave[17];
    int valor;
    struct Par *proximo;
} Par;

int funcaoHash(const char *chave)
{
    int hash = 0;
    for (int i = 0; chave[i] != '\0'; ++i)
        hash = (hash * 31 + chave[i]) % TAM;
    return hash;
}

void adicionar(Par *tabela[], const char *chave, int valor)
{
    int indice = funcaoHash(chave);
    Par *novoPar = (Par *)malloc(sizeof(Par));
    strcpy(novoPar->chave, chave);
    novoPar->valor = valor;
    novoPar->proximo = tabela[indice];
    tabela[indice] = novoPar;
}

int encontrar(Par *tabela[], const char *chave)
{
    int indice = funcaoHash(chave);
    Par *atual = tabela[indice];
    while (atual != NULL)
    {
        if (strcmp(atual->chave, chave) == 0)
            return atual->valor;
        atual = atual->proximo;
    }
    return 0;
}

void resetar(Par *tabela[], const char *chave)
{
    int indice = funcaoHash(chave);
    Par *atual = tabela[indice];
    while (atual != NULL)
    {
        if (strcmp(atual->chave, chave) == 0)
        {
            atual->valor = 0;
            return;
        }
        atual = atual->proximo;
    }
}

int main()
{
    Par *tabela[TAM] = {NULL};

    int c;
    char palavra[17];

    while (scanf("%d %s", &c, palavra) != EOF)
    {
        if (c == 1)
            adicionar(tabela, palavra, encontrar(tabela, palavra) + 1);

        else if (c == 2)

            printf("%d\n", encontrar(tabela, palavra));

        else if (c == 3)

            resetar(tabela, palavra);
    }

    for (int i = 0; i < TAM; ++i)
    {
        Par *atual = tabela[i];
        while (atual != NULL)
        {
            Par *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }

    return 0;
}
