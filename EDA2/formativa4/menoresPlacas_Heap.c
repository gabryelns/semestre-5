#include <stdio.h>
#include <stdlib.h>

#define menor(a, b) (a < b ? a : b)
#define maior(a, b) (b < a ? a : b)
#define Item int
#define chave(x) (x)
#define menos(a, b) (a > b)
#define swap(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpswap(a, b) \
    if (menos(b, a))  \
    swap(a, b)

Item ITEMNULL = -1;

typedef struct
{
    Item *heap;
    size_t tamanho, capacidade;
} heap;

void fixup(Item *heap, int i)
{
    for (; i > 1 && menos(heap[i / 2], heap[i]); i /= 2)
        swap(heap[i], heap[i / 2]);
}

void fixdown(Item *heap, size_t tamanho, int i)
{
    for (int maior = i * 2; i * 2 <= tamanho; i = maior, maior = i * 2)
    {
        if (maior < tamanho && menos(heap[maior], heap[maior + 1]))
            maior++;

        if (!menos(heap[i], heap[maior]))
            break;

        swap(heap[i], heap[maior]);
    }
}

heap inicia(size_t capacidade)
{
    heap fp = {.capacidade = capacidade, .tamanho = 0};
    fp.heap = malloc((capacidade + 1) * sizeof(Item));
    return fp;
}

void liberar(heap fp)
{
    free(fp.heap);
}

int vazia(heap fp)
{
    return fp.tamanho == 0;
}

void capacidade(heap *fp, size_t novaCapacidade)
{
    if (novaCapacidade <= fp->capacidade)
        return;

    fp->capacidade *= 4;
    fp->heap = realloc(fp->heap, (fp->capacidade + 1) * sizeof(Item));
}

void inserir(heap *fp, Item x)
{
    capacidade(fp, fp->tamanho + 1);
    fp->heap[++fp->tamanho] = x;
    fixup(fp->heap, fp->tamanho);
}

Item obterTopo(heap fp)
{
    return fp.heap[1];
}

Item extrairTopo(heap *fp)
{
    if (vazia(*fp))
        return ITEMNULL;

    Item topo = obterTopo(*fp);
    fp->heap[1] = fp->heap[fp->tamanho--];
    fixdown(fp->heap, fp->tamanho, 1);
    return topo;
}

int main()
{
    heap fp = inicia(16);
    int t, p, v[100];

    while (scanf(" %d %d", &t, &p) == 2)
    {
        if (t == 1)
            inserir(&fp, p);
        else
        {
            int n;
            for (n = 0; n < p; n++)
            {
                int topo = extrairTopo(&fp);
                if (topo == ITEMNULL)
                    break;
                v[n] = topo;
            }
            for (int i = 0; i < n; i++)
            {
                printf("%d%c", v[i], " \n"[i == n-1]);
                inserir(&fp, v[i]);
            }
        }
    }

    liberar(fp);

    return 0;
}
