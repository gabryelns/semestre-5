#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Automovel {
    char modelo[30];
    int ano;
    int renach;
};

struct proprietario {
    char nome[30];
    int idade;
    int cpf;
    int rg;
    struct Automovel carro[30];
};

int main() {
    struct proprietario pessoa[100];
    int qtdpro = 0;
    int qtdcar = 0;

    FILE *ptrArq;

    printf("DIGITE A QUANTIDADE DE USUARIOS A SEREM CADASTRADOS: ");
    scanf("%d", &qtdpro);

    ptrArq = fopen("binario.bin", "wb");

    if (ptrArq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    for (int i = 0; i < qtdpro; i++) {
        printf("\nDIGITE O NOME DO %d PROPRIETARIO A SER CADASTRADO: ", i + 1);
        scanf("%s", pessoa[i].nome);

        printf("DIGITE A IDADE DE %s: ", pessoa[i].nome);
        scanf("%d", &pessoa[i].idade);

        printf("DIGITE O CPF DE %s: ", pessoa[i].nome);
        scanf("%d", &pessoa[i].cpf);

        printf("DIGITE O RG DE %s: ", pessoa[i].nome);
        scanf("%d", &pessoa[i].rg);

        printf("\nDIGITE A QUANTIDADE DE CARROS AO TOTAL A SEREM CADASTRADOS PARA %s: ", pessoa[i].nome);
        scanf("%d", &qtdcar);

        for (int j = 0; j < qtdcar; j++) {
            printf("\nDIGITE O MODELO DO CARRO %d DE %s A SER CADASTRADO: ", j + 1, pessoa[i].nome);
            scanf("%s", pessoa[i].carro[j].modelo);

            printf("DIGITE O ANO DO CARRO %s DE %s A SER CADASTRADO: ", pessoa[i].carro[j].modelo, pessoa[i].nome);
            scanf("%d", &pessoa[i].carro[j].ano);

            printf("DIGITE O RENACH DO CARRO %s DE %s A SER CADASTRADO: ", pessoa[i].carro[j].modelo, pessoa[i].nome);
            scanf("%d", &pessoa[i].carro[j].renach);
        }
        
        fwrite(&pessoa[i], sizeof(struct proprietario), 1, ptrArq);
    }
    
     for (int i = 0; i < qtdpro; i++) {
        printf("\nNOME: %s\n", pessoa[i].nome);
        printf("IDADE: %d\n", pessoa[i].idade);
        printf("CPF: %d\n", pessoa[i].cpf);
        printf("RG: %d\n", pessoa[i].rg);

        for (int j = 0; j < qtdcar; j++) {
            printf("CARRO DE %s\n", pessoa[i].nome);
            printf("MODELO: %s\n", pessoa[i].carro[j].modelo);
            printf("ANO: %d\n", pessoa[i].carro[j].ano);
            printf("RENACH: %d\n", pessoa[i].carro[j].renach);
        }
    }

    fclose(ptrArq);

    return 0;
}
