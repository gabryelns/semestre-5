#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int vetor[n];
    long long int soma =0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    long long int media = (double)soma / n;

    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (vetor[i] > media)
        {
            printf(" %d", vetor[i]);
            count = 0;
        }
    }

    if(count) printf("0");

    printf("\n");
    return 0;
}