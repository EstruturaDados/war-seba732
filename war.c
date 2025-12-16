#include <stdio.h>

#define QTD_TERRITORIOS 5

typedef struct {
    char nome[30];
    char corExercito[20];
    int numeroTropas;
} Territorio;

int main() {
    Territorio mapa[QTD_TERRITORIOS] = {
        {"Oceania", "Branco", 2},
        {"África", "Vermelho", 4},
        {"Europa", "Verde", 6},
        {"América", "Amarelo", 5},
        {"Ásia", "Preto", 6}
    };

    printf("===== ESTADO ATUAL DO MAPA =====\n");

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].corExercito);
        printf("Número de Tropas: %d\n", mapa[i].numeroTropas);
    }

    return 0;
}