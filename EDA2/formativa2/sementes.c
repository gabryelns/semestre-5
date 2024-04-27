#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int identificador;
    int pontuacao;
} seed;

void swap(seed *a, seed *b)
{
    seed aux = *a;
    *a = *b;
    *b = aux;
}

int less(seed a, seed b)
{
    if (a.pontuacao < b.pontuacao)
        return 1;

    if (a.pontuacao == b.pontuacao && a.identificador < b.identificador)
        return 1;

    return 0;
}

int partition(seed *vet, int low, int high)
{
    int i = low;
    int j = high - 1;
    seed pivo = vet[high];

    while (i < j)
    {
        while (less(vet[i], pivo))
            i++;
        while (j > low && less(pivo, vet[j]))
            j--;
        if (i < j)
            swap(&vet[i], &vet[j]);
    }

    swap(&vet[i], &vet[high]);

    return i;
}

void quickSelect(seed vet[], int low, int high, int k)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        if (less(vet[high], vet[mid]))
            swap(&vet[mid], &vet[high]);
        if (less(vet[mid], vet[low]))
            swap(&vet[mid], &vet[low]);
        if (less(vet[mid], vet[high]))
            swap(&vet[mid], &vet[high]);

        int pivo = partition(vet, low, high);
        if (k < pivo)
            quickSelect(vet, low, pivo - 1, k);
        if (k > pivo)
            quickSelect(vet, pivo + 1, high, k);
    }
}

void merge(seed *vet, int low, int m, int high)
{
    int tamanho = (high - low) + 1;
    seed *aux = malloc(sizeof(seed) * tamanho);
    int i = low, j = m + 1, iaux = 0;

    while (i < m + 1 && j < high + 1)
    {
        if (vet[i].identificador < vet[j].identificador)
            aux[iaux++] = vet[i++];
        else
            aux[iaux++] = vet[j++];
    }

    while (i < m + 1)
        aux[iaux++] = vet[i++];
    while (j < high + 1)
        aux[iaux++] = vet[j++];

    iaux = 0;
    while (low <= high)
    {
        vet[low++] = aux[iaux++];
    }
    free(aux);
}

void mergeSort(seed *vet, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(vet, low, mid);
        mergeSort(vet, mid + 1, high);
        merge(vet, low, mid, high);
    }
}

int main()
{
    int qtdsel, pontuacao;
    unsigned int identificador;
    scanf("%d", &qtdsel);
    seed vetor[10000000];

    int i = 0;
    while ((scanf("%u %d", &identificador, &pontuacao)) != EOF)
    {
        vetor[i].identificador = identificador;
        vetor[i].pontuacao = pontuacao;
        i++;
    }

    quickSelect(vetor, 0, i - 1, qtdsel - 1);

    mergeSort(vetor, 0, qtdsel - 1);

    for (i = 0; i < qtdsel; i++)
    {
        printf("%u %d\n", vetor[i].identificador, vetor[i].pontuacao);
    }

    return 0;
}