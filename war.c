#include <stdio.h>   // Inclui a biblioteca padrão de entrada e saída, necessária para printf e scanf

#define QTD_TERRITORIOS 5   // Define uma constante para a quantidade de territórios que teremos no vetor

// Definição de uma estrutura chamada Territorio
typedef struct {
    char nome[30];         // Armazena o nome do território (até 30 caracteres)
    char corExercito[20];  // Armazena a cor do exército dominante (até 20 caracteres)
    int numeroTropas;      // Armazena o número de tropas no território
} Territorio;

int main() {   // Função principal do programa
    // Criação e inicialização de um vetor estático com 5 territórios
    Territorio mapa[QTD_TERRITORIOS] = {
        {"Oceania", "Branco", 2},     // Primeiro território
        {"África", "Vermelho", 4},    // Segundo território
        {"Europa", "Verde", 6},       // Terceiro território
        {"América", "Amarelo", 5},    // Quarto território
        {"Ásia", "Preto", 6}          // Quinto território
    };

    printf("===== ESTADO ATUAL DO MAPA =====\n");  // Imprime um cabeçalho no console

    // Laço de repetição para percorrer todos os territórios do vetor
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritório %d\n", i + 1);                // Imprime o número do território 
        printf("Nome: %s\n", mapa[i].nome);               // Imprime o nome do território
        printf("Cor do Exército: %s\n", mapa[i].corExercito); // Imprime a cor do exército
        printf("Número de Tropas: %d\n", mapa[i].numeroTropas); // Imprime o número de tropas
    }

    return 0;   // Finaliza o programa 
}