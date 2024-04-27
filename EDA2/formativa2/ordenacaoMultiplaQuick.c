#include <stdio.h>
#include <stdlib.h>

struct Vetor
{
    int line;
    int col;
    float dado;
};

void swap(struct Vetor *a, struct Vetor *b);

int mediana_de_tres(struct Vetor *v, int low, int high)
{
    int mid = (low + high) / 2;
    if (v[low].dado > v[mid].dado)
        swap(&v[low], &v[mid]);
    if (v[mid].dado > v[high].dado)
        swap(&v[mid], &v[high]);
    if (v[low].dado > v[mid].dado)
        swap(&v[low], &v[mid]);
    return mid;
}

void swap(struct Vetor *a, struct Vetor *b)
{
    struct Vetor temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(struct Vetor *v, int low, int high)
{
    int mid = mediana_de_tres(v, low, high);
    swap(&v[mid], &v[high]);
    float pivot = v[high].dado;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (v[j].dado > pivot || (v[j].dado == pivot && (v[j].line < v[high].line || (v[j].line == v[high].line && v[j].col < v[high].col))))
        {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return i + 1;
}

void quicksort(struct Vetor *v, int low, int high)
{
    if (low < high)
    {
        int pi = particionar(v, low, high);
        quicksort(v, low, pi - 1);
        quicksort(v, pi + 1, high);
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--)
    {

        int m, n;
        scanf("%d%d", &m, &n);

        int tam = n * m;
        struct Vetor *vetor = malloc(tam * sizeof(struct Vetor));

        int indexm = 1;
        int indexn = 1;

        for (int i = 0; i < tam; i++)
        {
            if (indexn > n)
            {
                indexn = 1;
                indexm++;
            }
            scanf("%f", &vetor[i].dado);

            vetor[i].line = indexm;
            vetor[i].col = indexn;

            indexn++;
        }

        quicksort(vetor, 0, tam - 1);

        for (int i = 0; i < tam; i++)
        {
            if (i > 0)
                printf(" ");

            printf("%d,%d", vetor[i].line, vetor[i].col);
        }

        printf("\n");

        free(vetor);
    }

    return 0;
}
