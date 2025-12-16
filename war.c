#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // Para srand e rand, garantindo aleatoriedade

// Definição da estrutura Territorio
typedef struct {
    char nome[30];       // Nome do território
    char cor[10];        // Cor do exército dominante
    int tropas;          // Número de tropas
} Territorio;

// Função para cadastrar os territórios dinamicamente
Territorio* cadastrarTerritorios(int qtd) {
    // Alocação dinâmica do vetor de territórios usando calloc
    Territorio* mapa = (Territorio*) calloc(qtd, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    for (int i = 0; i < qtd; i++) {
        printf("\n=== Cadastro do Território %d ===\n", i + 1);
        
        printf("Nome do território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0'; // Remove \n do fgets

        printf("Cor do exército: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar(); // Limpa buffer do teclado
    }

    return mapa;
}

// Função para exibir todos os territórios
void exibirTerritorios(Territorio* mapa, int qtd) {
    printf("\n===== ESTADO ATUAL DO MAPA =====\n");
    for (int i = 0; i < qtd; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Número de Tropas: %d\n", mapa[i].tropas);
    }
}

// Função para simular um ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    printf("\n%s (%s) está atacando %s (%s)\n", 
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    int dadoAtacante = rand() % 6 + 1;  // Simula dado do atacante (1 a 6)
    int dadoDefensor = rand() % 6 + 1;  // Simula dado do defensor (1 a 6)

    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        // Atacante vence: transfere cor e metade das tropas
        printf("Atacante venceu!\n");
        defensor->tropas = atacante->tropas / 2;
        strcpy(defensor->cor, atacante->cor);
    } else {
        // Atacante perde uma tropa
        printf("Atacante perdeu!\n");
        if (atacante->tropas > 0)
            atacante->tropas -= 1;
    }
}

// Função para liberar memória alocada dinamicamente
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int qtdTerritorios;
    printf("Digite o número de territórios: ");
    scanf("%d", &qtdTerritorios);
    getchar(); // Limpa buffer do teclado

    // Cadastro de territórios
    Territorio* mapa = cadastrarTerritorios(qtdTerritorios);

    // Exibição inicial dos territórios
    exibirTerritorios(mapa, qtdTerritorios);

    // Exemplo de ataque (interatividade básica)
    int atk, def;
    printf("\nEscolha o território atacante (1 a %d): ", qtdTerritorios);
    scanf("%d", &atk);
    printf("Escolha o território defensor (1 a %d): ", qtdTerritorios);
    scanf("%d", &def);

    // Validação: não atacar território da mesma cor
    if (strcmp(mapa[atk - 1].cor, mapa[def - 1].cor) == 0) {
        printf("Não é permitido atacar território da mesma cor!\n");
    } else {
        atacar(&mapa[atk - 1], &mapa[def - 1]);
        exibirTerritorios(mapa, qtdTerritorios); // Mostra o estado atualizado
    }

    // Libera a memória
    liberarMemoria(mapa);

    return 0;
}