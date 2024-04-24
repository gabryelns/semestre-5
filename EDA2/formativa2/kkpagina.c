#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *vetor, int n)
{
    int maior = vetor[0];
    for (int i = 1; i < n; i++){
        if (vetor[i] > maior){
            maior = vetor[i];
        }
    }

    for (int exp = 1; maior / exp > 0; exp *= 10){
        int *saida = (int *)malloc(n * sizeof(int));
        int cont[10] = {0};

        for (int i = 0; i < n; i++){
            cont[(vetor[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++){
            cont[i] += cont[i - 1];
        }
        for (int i = n - 1; i >= 0; i--){
            saida[cont[(vetor[i] / exp) % 10] - 1] = vetor[i];
            cont[(vetor[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++){
            vetor[i] = saida[i];
        }
        free(saida);
    }
}

int main(){
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);

    int *vetor = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    radix_sort(vetor, n);

    int inicio = p * x;

    int fim = (p + 1) * x;
    if (fim > n)
        fim = n;

    for (int i = inicio; i < fim; i++)
    {
        printf("%d\n", vetor[i]);
    }

    free(vetor);

    return 0;
}
