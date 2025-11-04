#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se há sobreposição
int verificaSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        if (diagonal == 1) { // Diagonal principal (↘)
            l += i;
            c += i;
        } else if (diagonal == -1) { // Diagonal secundária (↙)
            l += i;
            c -= i;
        } else if (direcao == 0) { // Horizontal →
            c += i;
        } else if (direcao == 1) { // Vertical ↓
            l += i;
        }

        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO || c < 0 || tabuleiro[l][c] == NAVIO) {
            return 1; // Sobreposição ou fora dos limites
        }
    }
    return 0;
}

// Função para posicionar navio
void posicionaNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == -1) {
            l += i;
            c -= i;
        } else if (direcao == 0) {
            c += i;
        } else if (direcao == 1) {
            l += i;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas dos navios
    int navios[4][4] = {
        {2, 2, 0, 0},  // Horizontal
        {5, 1, 1, 0},  // Vertical
        {0, 0, -1, 1}, // Diagonal principal ↘
        {0, 9, -1, -1} // Diagonal secundária ↙
    };

    // Posiciona os navios
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int direcao = navios[i][2];
        int diagonal = navios[i][3];

        if (!verificaSobreposicao(tabuleiro, linha, coluna, direcao, diagonal)) {
            posicionaNavio(tabuleiro, linha, coluna, direcao, diagonal);
        } else {
            printf("Erro ao posicionar navio %d: sobreposição ou fora dos limites.\n", i + 1);
        }
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}