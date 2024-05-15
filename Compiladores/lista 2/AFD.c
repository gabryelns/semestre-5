#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ESTADOS 100
#define MAX_ALFABETO 26

typedef struct
{
    int transicoes[MAX_ESTADOS][MAX_ALFABETO];
    int num_estados;
    char alfabeto[MAX_ALFABETO];
    int estado_inicial;
    int num_estados_finais;
    int estados_finais[MAX_ESTADOS];
} AFD;

void ler_afd(AFD *afd)
{
    scanf("%d", &afd->num_estados);

    int tam_alfabeto;
    scanf("%d", &tam_alfabeto);
    for (int i = 0; i < tam_alfabeto; i++)
    {
        scanf(" %c", &afd->alfabeto[i]);
    }

    int num_transicoes = afd->num_estados * tam_alfabeto;
    for (int i = 0; i < num_transicoes; i++)
    {
        int origem, destino;
        char simbolo;
        scanf("%d %c %d", &origem, &simbolo, &destino);
        afd->transicoes[origem][simbolo - 'a'] = destino;
    }

    scanf("%d", &afd->estado_inicial);

    scanf("%d", &afd->num_estados_finais);
    for (int i = 0; i < afd->num_estados_finais; i++)
    {
        scanf("%d", &afd->estados_finais[i]);
    }
}

bool simular_afd(AFD *afd, const char *palavra)
{
    int estado_atual = afd->estado_inicial;

    for (int i = 0; i < strlen(palavra); i++)
    {
        char simbolo = palavra[i];
        int indice_simbolo = -1;
        for (int j = 0; j < strlen(afd->alfabeto); j++)
        {
            if (afd->alfabeto[j] == simbolo)
            {
                indice_simbolo = j;
                break;
            }
        }
        if (indice_simbolo == -1)
            return false;

        estado_atual = afd->transicoes[estado_atual][indice_simbolo];
    }

    for (int i = 0; i < afd->num_estados_finais; i++)
    {
        if (estado_atual == afd->estados_finais[i])
            return true;
    }

    return false;
}

int main()
{
    AFD afd;
    ler_afd(&afd);

    char palavra[100];
    scanf("%s", palavra);

    if (simular_afd(&afd, palavra))
    {
        printf("Aceito\n");
    }
    else
    {
        printf("Rejeitado\n");
    }

    return 0;
}
