#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r)
{
    int *aux = malloc(sizeof(int) * (r - l + 1));
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
    {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
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

void merge_sort(int *v, int l, int r)
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
    int n;
    int i;

    scanf("%d", &n);

    int *vetor = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    merge_sort(vetor, 0, i - 1);

    printf("%d", vetor[0]);

    for (int j = 1; j < i; j++)
        printf(" %d", vetor[j]);

    printf("\n");
}