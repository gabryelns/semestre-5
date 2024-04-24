#include <stdio.h>
#include <stdlib.h>

struct Vetor
{
    int line;
    int col;
    float dado;
};

void merge(struct Vetor *v, int l, int m, int r)
{
    struct Vetor *aux = malloc(sizeof(struct Vetor) * (r - l + 1));
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
    {
        if (v[i].dado > v[j].dado)
            aux[k++] = v[i++];
        else if (v[i].dado < v[j].dado)
            aux[k++] = v[j++];
        else
        {
            if (v[i].line < v[j].line)
                aux[k++] = v[i++];
            else if (v[i].line > v[j].line)
                aux[k++] = v[j++];
            else
            {
                if (v[i].col < v[j].col)
                    aux[k++] = v[i++];
                else
                    aux[k++] = v[j++];
            }
        }
    }

    while (i <= m)
        aux[k++] = v[i++];

    while (j <= r)
        aux[k++] = v[j++];

    k = 0;

    for (i = l; i <= r; i++)
        v[i] = aux[k++];

    free(aux);
}

void merge_sort(struct Vetor *v, int l, int r)
{
    if (l >= r)
        return;

    int meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);
    merge(v, l, meio, r);
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

        merge_sort(vetor, 0, tam - 1);

        for (int i = 0; i < tam; i++)
        {
            if (i > 0)
                printf(" ");

            printf("%d,%d", vetor[i].line, vetor[i].col, vetor[i].dado);
        }

        printf("\n");

        free(vetor);
    }

    return 0;
}