#include <stdio.h>
#include <stdlib.h>

#define troca(a,b) {int temp = a; a = b; b = temp;}

typedef struct {
    int *dados;
    int tamanho;
    int posicao_livre;
} min_heap;

min_heap* criar_min_heap(int capacidade) {
    min_heap *novo_heap = (min_heap*) malloc(sizeof(min_heap));
    novo_heap->tamanho = capacidade;
    novo_heap->dados = (int*) malloc(capacidade * sizeof(int));
    novo_heap->posicao_livre = 0;
    return novo_heap;
}

void ajustar_descendo(min_heap *heap, int inicio) {
    int k = inicio;
    int fim = heap->posicao_livre - 1;
    int esquerdo = 0;

    while (2 * k + 1 <= fim) {
        esquerdo = 2 * k + 1;
        if (esquerdo < fim && heap->dados[esquerdo + 1] < heap->dados[esquerdo])
            esquerdo++;
        if (heap->dados[esquerdo] < heap->dados[k]) {
            troca(heap->dados[esquerdo], heap->dados[k]);
            k = esquerdo;
        } else {
            break;
        }
    }
}

void ajustar_subindo(min_heap *heap, int inicio) {
    int k = inicio;
    int pai = (k - 1) / 2;

    while (k > 0 && heap->dados[k] < heap->dados[pai]) {
        troca(heap->dados[k], heap->dados[pai]);
        k = pai;
        pai = (k - 1) / 2;
    }
}

int remover_min(min_heap *heap, int indice) {
    int menor = heap->dados[indice];
    heap->posicao_livre--;
    troca(heap->dados[indice], heap->dados[heap->posicao_livre]);
    ajustar_descendo(heap, indice);
    return menor;
}

void inserir_heap(min_heap *heap, int valor) {
    heap->dados[heap->posicao_livre] = valor;
    ajustar_subindo(heap, heap->posicao_livre);
    heap->posicao_livre++;
}

int main() {
    int num_elementos = 0, limite = 0;
    scanf("%d %d", &num_elementos, &limite);

    min_heap *heap_a = criar_min_heap(num_elementos);
    int *heap_b = (int*) malloc(num_elementos * sizeof(int));
    int posicao_livre_b = 0, num_combinacoes = 0;
    int *combinacoes = (int*) malloc(num_elementos * sizeof(int));
    int retirado;

    for (int i = 0; i < num_elementos; i++) {
        int valor;
        scanf("%d", &valor);
        inserir_heap(heap_a, valor);
    }

    while (heap_a->posicao_livre > 0) {
        retirado = remover_min(heap_a, 0);

        if (posicao_livre_b == 0) {
            heap_b[posicao_livre_b++] = retirado;
            continue;
        }

        if (retirado - heap_b[posicao_livre_b - 1] <= limite && retirado - heap_b[posicao_livre_b - 1] > 0) {
            combinacoes[num_combinacoes++] = retirado + heap_b[--posicao_livre_b];
        } else {
            heap_b[posicao_livre_b++] = retirado;
        }
    }

    printf("%d\n", num_combinacoes);
    for (int i = 0; i < num_combinacoes; i++) {
        printf("%d ", combinacoes[i]);
    }
    printf("\n");

    free(heap_a->dados);
    free(heap_a);
    free(heap_b);
    free(combinacoes);

    return 0;
}
