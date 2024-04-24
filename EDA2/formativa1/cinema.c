#include <stdio.h>

void marcarLugarOcupado(char mapa[20][25], char lugar[]) {
    int fileira = lugar[0] - 'A'; // Convertendo a letra da fileira para índice
    int num_lugar = lugar[1] - '0'; // Convertendo o número do lugar para índice
    mapa[fileira][num_lugar - 1] = 'X'; // Marcar o lugar como ocupado
}

void imprimirMapa(char mapa[20][25], int num_fileiras, int num_lugares) {
    printf("  ");
    for (int i = 1; i <= num_lugares; ++i) {
        printf("%02d ", i);
    }
    printf("\n");

    for (int i = 0; i < num_fileiras; ++i) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < num_lugares; ++j) {
            printf("%2c ", mapa[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_fileiras, num_lugares;
    char bilhete[3];
    
    scanf("%d %d", &num_fileiras, &num_lugares);

    char mapa[20][25];

    for (int i = 0; i < num_fileiras; ++i) {
        for (int j = 0; j < num_lugares; ++j) {
            mapa[i][j] = '-';
        }
    }

    while (scanf("%s", bilhete) != EOF) {
        marcarLugarOcupado(mapa, bilhete);
    }

    imprimirMapa(mapa, num_fileiras, num_lugares);

    return 0;
}
