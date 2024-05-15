#include <stdio.h>

typedef struct
{
    int pid;
    int tempo;
} process;

void remover(process *v, int j, int n){

    for (int i = j; i < n; i++)
    {
        process aux = v[i+1];
        v[i+1] = v[i];
        v[i] = aux;
    }
}
int main()
{
    int n, quantum, auxiliar, tempototal = 0;

    scanf("%d\n%d", &n, &quantum);

    process vetor[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &vetor[i].pid, &auxiliar);
        vetor[i].tempo = auxiliar * 1000;
    }

    int aux = n;
    while (aux > 0)
    {
        for (int i = 0; i < aux; i++)
        {

            if (vetor[i].tempo > quantum)
            {
                tempototal += quantum;
                vetor[i].tempo -= quantum;
            }

            else
            {
                tempototal += vetor[i].tempo;
                printf("%d (%d)\n", vetor[i].pid, tempototal);
                remover(vetor, i, n);
                aux--;
                i--;

            }
        }
    }

    return 0;
}