#include <stdio.h>
#include <string.h>

void construir_posordem(char *preordem, char *inordem, char *posordem, int n, int *index){

    if (n <= 0) {
        return;
    }

    char raiz = preordem[0];
    
    int indiceRaiz;
    for (indiceRaiz = 0; indiceRaiz < n; indiceRaiz++) {
        if (inordem[indiceRaiz] == raiz) {
            break;
        }
    }

    construir_posordem(preordem + 1, inordem, posordem, indiceRaiz, index);
    construir_posordem(preordem + indiceRaiz + 1, inordem + indiceRaiz + 1, posordem, n - indiceRaiz - 1, index);
    
    posordem[*index] = raiz;
    (*index)++;

}

int main() {
    int c;
    scanf("%d", &c);

    while (c--) {
        int n;
        char s1[53], s2[53];
        scanf("%d %s %s", &n, s1, s2);

        char posordem[n];
        int pIndex = 0;

        construir_posordem(s1, s2, posordem, n, &pIndex);
        posordem[n] = '\0';

        printf("%s\n", posordem);
    }

    return 0;
}