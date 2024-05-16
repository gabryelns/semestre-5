#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int qtd;
} Carc;

void merge(Carc *v, int l, int m, int r)
{
    Carc *aux = malloc(sizeof(Carc) * (r - l + 1));
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
    {
        if (v[i].qtd <= v[j].qtd)
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

void merge_sort(Carc *v, int l, int r)
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
    char text[1001];

    while (scanf("%s", text) != EOF)
    {
        int freq[128] = {0};
        for (int i = 0; text[i] != '\0'; i++)
        {
            freq[(int)text[i]]++;
        }

        Carc caracteres[128];
        int num = 0;
        for (int i = 0; i < 128; i++)
        {
            if (freq[i] > 0)
            {
                caracteres[num].id = i;
                caracteres[num].qtd = freq[i];
                num++;
            }
        }

        merge_sort(caracteres, 0, num - 1);

        for (int i = 0; i < num; i++)
        {
            printf("%d %d\n", caracteres[i].id, caracteres[i].qtd);
        }

        printf("\n");
    }

    return 0;
}