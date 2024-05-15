#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int index;
    int chave;
} tabela;

int main()
{
    int n, num = 0;

    scanf("%d", &n);

    while (num < n)
    {
        int m, c, aux, chave;

        scanf("%d %d", &m, &c);

        tabela vetor[m];

        for (int i = 0; i < c; i++)
        {
            scanf("%d", &chave);
            aux = chave % m;

            vetor[i].chave = chave;
            vetor[i].index = aux;
        }

        for (int i = 0; i < m; i++)
        {
            printf("%d", i);

            for (int j = 0; j < m; j++)
            {
                if(vetor[j].index == i){
                    printf(" -> %d", vetor[j].chave);
                }
            }
            printf(" -> \\\n");
        }
        printf("\n");

        num++;
    }

    return 0;
}