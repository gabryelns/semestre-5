#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Veiculo
{
    char placa[20];
    char modelo[50];
    int renach;
    struct Veiculo *proximo;
} Veiculo;

typedef struct Proprietario
{
    char nome[50];
    int idade;
    char cpf[14];
    Veiculo *veiculos;
    struct Proprietario *proximo;
} Proprietario;

int compararCPF(const char *cpf1, const char *cpf2)
{
    return strcmp(cpf1, cpf2);
}

int cpfExiste(Proprietario *cabeca, const char *cpf)
{
    Proprietario *proprietario = cabeca;
    while (proprietario != NULL)
    {
        if (strcmp(proprietario->cpf, cpf) == 0)
        {
            return 1;
        }
        proprietario = proprietario->proximo;
    }
    return 0;
}

Veiculo *criarVeiculo(char placa[], char modelo[], int renach)
{
    Veiculo *novoVeiculo = (Veiculo *)malloc(sizeof(Veiculo));
    if (novoVeiculo == NULL)
    {
        printf("Erro ao alocar memoria para o veiculo.\n");
        exit(1);
    }
    strcpy(novoVeiculo->placa, placa);
    strcpy(novoVeiculo->modelo, modelo);
    novoVeiculo->renach = renach;
    novoVeiculo->proximo = NULL;
    return novoVeiculo;
}

Proprietario *criarProprietario(char nome[], int idade, char cpf[])
{
    Proprietario *novoProprietario = (Proprietario *)malloc(sizeof(Proprietario));
    if (novoProprietario == NULL)
    {
        printf("Erro ao alocar memoria para o proprietário.\n");
        exit(1);
    }
    strcpy(novoProprietario->nome, nome);
    novoProprietario->idade = idade;
    strcpy(novoProprietario->cpf, cpf);
    novoProprietario->veiculos = NULL;
    novoProprietario->proximo = NULL;
    return novoProprietario;
}

void adicionarVeiculo(Proprietario *proprietario, char placa[], char modelo[], int renach)
{
    Veiculo *novoVeiculo = criarVeiculo(placa, modelo, renach);
    if (proprietario->veiculos == NULL)
    {
        proprietario->veiculos = novoVeiculo;
    }
    else
    {
        Veiculo *temp = proprietario->veiculos;
        while (temp->proximo != NULL)
        {
            temp = temp->proximo;
        }
        temp->proximo = novoVeiculo;
    }
}

void inserirOrdenado(Proprietario **cabeca, Proprietario *novoProprietario)
{
    Proprietario *atual = *cabeca;
    Proprietario *anterior = NULL;

    while (atual != NULL && compararCPF(novoProprietario->cpf, atual->cpf) > 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL)
    {
        novoProprietario->proximo = *cabeca;
        *cabeca = novoProprietario;
    }
    else
    {
        anterior->proximo = novoProprietario;
        novoProprietario->proximo = atual;
    }
}

void liberarMemoria(Proprietario *cabeca);

void salvarProprietariosOrdenados(Proprietario *cabeca, const char *nomeArquivo)
{
    Proprietario *cabecaOrdenada = NULL;
    Proprietario *proprietario = cabeca;

    while (proprietario != NULL)
    {
        Proprietario *proximo = proprietario->proximo;
        inserirOrdenado(&cabecaOrdenada, proprietario);
        proprietario = proximo;
    }

    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    Proprietario *temp = cabecaOrdenada;
    while (temp != NULL)
    {
        fwrite(temp, sizeof(Proprietario), 1, arquivo);
        temp = temp->proximo;
    }

    fclose(arquivo);

    liberarMemoria(cabecaOrdenada);
}

void salvarVeiculos(Proprietario *cabeca, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    Proprietario *proprietario = cabeca;
    while (proprietario != NULL)
    {
        Veiculo *veiculo = proprietario->veiculos;
        while (veiculo != NULL)
        {
            fwrite(veiculo, sizeof(Veiculo), 1, arquivo);
            veiculo = veiculo->proximo;
        }
        proprietario = proprietario->proximo;
    }

    fclose(arquivo);
}

void liberarMemoria(Proprietario *cabeca)
{
    while (cabeca != NULL)
    {
        Proprietario *tempProprietario = cabeca;
        cabeca = cabeca->proximo;
        Veiculo *veiculo = tempProprietario->veiculos;
        while (veiculo != NULL)
        {
            Veiculo *tempVeiculo = veiculo;
            veiculo = veiculo->proximo;
            free(tempVeiculo);
        }
        free(tempProprietario);
    }
}

Proprietario *lerProprietarios(const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }

    Proprietario *cabeca = NULL;
    Proprietario *ultimo = NULL;
    while (1)
    {
        Proprietario *novoProprietario = (Proprietario *)malloc(sizeof(Proprietario));
        if (novoProprietario == NULL)
        {
            printf("Erro ao alocar memória para o proprietário.\n");
            exit(1);
        }

        size_t elementos_lidos = fread(novoProprietario, sizeof(Proprietario), 1, arquivo);
        if (elementos_lidos != 1)
        {
            free(novoProprietario);
            break;
        }

        novoProprietario->proximo = NULL;

        if (cabeca == NULL)
        {
            cabeca = novoProprietario;
        }
        else
        {
            ultimo->proximo = novoProprietario;
        }

        ultimo = novoProprietario;
    }

    fclose(arquivo);
    return cabeca;
}

Veiculo *lerVeiculos(const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(1);
    }

    Veiculo *cabeca = NULL;
    Veiculo *ultimo = NULL;
    while (1)
    {
        Veiculo *novoVeiculo = (Veiculo *)malloc(sizeof(Veiculo));
        if (novoVeiculo == NULL)
        {
            printf("Erro ao alocar memória para o veículo.\n");
            exit(1);
        }

        size_t elementos_lidos = fread(novoVeiculo, sizeof(Veiculo), 1, arquivo);
        if (elementos_lidos != 1)
        {
            free(novoVeiculo);
            break;
        }

        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';
        novoVeiculo->modelo[strcspn(novoVeiculo->modelo, "\n")] = '\0';

        novoVeiculo->proximo = NULL;

        if (cabeca == NULL)
        {
            cabeca = novoVeiculo;
        }
        else
        {
            ultimo->proximo = novoVeiculo;
        }

        ultimo = novoVeiculo;
    }

    fclose(arquivo);
    return cabeca;
}

void imprimirDados(Proprietario *cabeca)
{
    Proprietario *proprietario = cabeca;
    while (proprietario != NULL)
    {
        printf("Nome do Proprietario: %s\n", proprietario->nome);
        printf("Idade: %d\n", proprietario->idade);
        printf("CPF: %s\n", proprietario->cpf);

        printf("Veiculos:\n");
        Veiculo *veiculo = proprietario->veiculos;
        while (veiculo != NULL)
        {
            printf("  Placa: %s, Modelo: %s, Renach: %d\n", veiculo->placa, veiculo->modelo, veiculo->renach);
            veiculo = veiculo->proximo;
        }

        printf("\n");

        proprietario = proprietario->proximo;
    }
}

int main()
{

    Proprietario *cabeca = NULL;

    while (1)
    {
        char nome[50], cpf[30];
        int idade, renach;
        printf("\nDigite o nome do proprietario (ou 'sair' para terminar): ");
        scanf("%s", nome);
        if (strcmp(nome, "sair") == 0)
        {
            break;
        }
        printf("Digite a idade do proprietario: ");
        scanf("%d", &idade);
        printf("Digite o cpf do proprietario: ");
        scanf("%s", cpf);

        Proprietario *novoProprietario = criarProprietario(nome, idade, cpf);

        if (cpfExiste(cabeca, cpf))
        {
            printf("CPF ja existe na lista de proprietarios. Encerrando o programa.\n\n");
            liberarMemoria(cabeca);
            return 0;
        }

        while (1)
        {
            char placa[20], modelo[50];
            printf("Digite a placa do veiculo (ou 'sair' para adicionar outro proprietario): ");
            scanf("%s", placa);
            if (strcmp(placa, "sair") == 0)
            {
                break;
            }
            printf("Digite o modelo do veiculo: ");
            scanf("%s", modelo);
            printf("Digite o renach do veiculo: ");
            scanf("%d", &renach);

            adicionarVeiculo(novoProprietario, placa, modelo, renach);
        }

        if (cabeca == NULL)
        {
            cabeca = novoProprietario;
        }
        else
        {
            Proprietario *temp = cabeca;
            while (temp->proximo != NULL)
            {
                temp = temp->proximo;
            }
            temp->proximo = novoProprietario;
        }
    }

    salvarProprietariosOrdenados(cabeca, "proprietarios.bin");
    salvarVeiculos(cabeca, "veiculos.bin");

    liberarMemoria(cabeca);

    Proprietario *cabecaProprietario = lerProprietarios("proprietarios.bin");
    Veiculo *cabecaVeiculo = lerVeiculos("veiculos.bin");

    printf("Dados dos proprietarios e veiculos:\n\n");
    imprimirDados(cabecaProprietario);

    liberarMemoria(cabecaProprietario);

    while (cabecaVeiculo != NULL)
    {
        Veiculo *tempVeiculo = cabecaVeiculo;
        cabecaVeiculo = cabecaVeiculo->proximo;
        free(tempVeiculo);
    }

    return 0;
}
