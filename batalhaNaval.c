#include <stdio.h>

int main() {
#define TAMANHO 10
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (coluna + NAVIO > TAMANHO) return 0; // Valida os limites do tabuleiro
    
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0; // Verifica sobreposição
    }
    
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + NAVIO > TAMANHO) return 0; // Valida os limites do tabuleiro
    
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0; // Verifica sobreposição
    }
    
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Coordenadas fixas para os navios
    int linhaH = 2, colunaH = 3; // Navio horizontal
    int linhaV = 5, colunaV = 6; // Navio vertical
    
    // Posiciona os navios garantindo que não se sobreponham
    if (!posicionarNavioHorizontal(tabuleiro, linhaH, colunaH)) {
        printf("Falha ao posicionar navio horizontal!\n");
    }
    if (!posicionarNavioVertical(tabuleiro, linhaV, colunaV)) {
        printf("Falha ao posicionar navio vertical!\n");
    }
    
    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}


    return 0;
}
