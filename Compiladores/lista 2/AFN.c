#include <stdio.h>
#include <stdbool.h>

#define MAX_ESTADOS 100
#define MAX_ALFABETO 26

bool ehEstadoFinal(int estado, int estados_finais[], int num_estados_finais)
{
    for (int i = 0; i < num_estados_finais; i++)
    {
        if (estado == estados_finais[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int num_estados, num_simbolos;
    char alfabeto[MAX_ALFABETO];
    int tabela_transicao[MAX_ESTADOS][MAX_ALFABETO][MAX_ESTADOS];
    int estado_inicial, num_estados_finais;
    int estados_finais[MAX_ESTADOS];
    char palavra[MAX_ESTADOS];

    scanf("%d", &num_estados);
    scanf("%d", &num_simbolos);
    for (int i = 0; i < num_simbolos; i++)
    {
        scanf(" %c", &alfabeto[i]);
    }
    for (int i = 0; i < num_estados; i++)
    {
        for (int j = 0; j < num_simbolos; j++)
        {
            int origem, num_destinos;
            scanf("%d %c %d", &origem, &alfabeto[j], &num_destinos);
            for (int k = 0; k < num_destinos; k++)
            {
                scanf("%d", &tabela_transicao[origem][j][k]);
            }
        }
    }
    scanf("%d", &estado_inicial);
    scanf("%d", &num_estados_finais);
    for (int i = 0; i < num_estados_finais; i++)
    {
        scanf("%d", &estados_finais[i]);
    }
    scanf("%s", palavra);

    int estados_atuais[MAX_ESTADOS];
    estados_atuais[0] = estado_inicial;
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        int novo_estados_atuais[MAX_ESTADOS];
        int num_novos_estados = 0;
        for (int j = 0; j < num_estados; j++)
        {
            if (ehEstadoFinal(estados_atuais[j], estados_finais, num_estados_finais))
            {
                continue;
            }
            for (int k = 0; k < num_simbolos; k++)
            {
                for (int l = 0; l < tabela_transicao[estados_atuais[j]][k][0]; l++)
                {
                    int destino = tabela_transicao[estados_atuais[j]][k][l + 1];
                    bool estado_ja_adicionado = false;
                    for (int m = 0; m < num_novos_estados; m++)
                    {
                        if (novo_estados_atuais[m] == destino)
                        {
                            estado_ja_adicionado = true;
                            break;
                        }
                    }
                    if (!estado_ja_adicionado)
                    {
                        novo_estados_atuais[num_novos_estados++] = destino;
                    }
                }
            }
            for (int j = 0; j < num_novos_estados; j++)
            {
                estados_atuais[j] = novo_estados_atuais[j];
            }
        }

        for (int i = 0; i < num_estados; i++)
        {
            if (ehEstadoFinal(estados_atuais[i], estados_finais, num_estados_finais))
            {
                printf("Aceito\n");
                return 0;
            }
        }

        printf("Rejeito\n");
        return 0;
    }
}