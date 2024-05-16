#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long int id;
    int qtd;
} tabela;

int main()
{
    int n, somatotal = 0, m, c;

    scanf("%d", &n);

    tabela *vetor = malloc(n * sizeof(tabela));

    for (int i = 0; i < n; i++)
    {
        vetor[i].qtd = 0;

        scanf("%lld %d", &vetor[i].id, &vetor[i].qtd);
        somatotal += vetor[i].qtd;
    }
    free(vetor);
    printf("%d", somatotal);

    return 0;
}