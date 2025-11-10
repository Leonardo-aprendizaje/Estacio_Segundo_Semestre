#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para usar usleep()

#define LINHAS 10
#define COLUNAS 20

int main() {
    char tela[LINHAS][COLUNAS + 1]; // +1 pro caractere nulo '\0'
    char *ptr; // ponteiro para percorrer a matriz
    int x = 0, y = 0; // posição do caractere
    int dx = 1, dy = 1; // direção (1 = direita/baixo, -1 = esquerda/cima)

    // Inicializa a tela com espaços
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tela[i][j] = ' ';
        }
        tela[i][COLUNAS] = '\0';
    }

    while (1) {
        system("clear"); // ou "cls" no Windows

        // Limpa a tela
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                tela[i][j] = ' ';
            }
        }

        // Calcula posição via ponteiro
        ptr = &tela[y][x]; // aponta pro elemento atual
        *ptr = '*'; // desenha o ponto

        // Mostra a matriz
        for (int i = 0; i < LINHAS; i++) {
            printf("%s\n", tela[i]);
        }

        usleep(80000); // pausa (80 ms)

        // Atualiza posição
        x += dx;
        y += dy;

        // Verifica limites horizontais
        if (x == COLUNAS - 1 || x == 0)
            dx *= -1;

        // Verifica limites verticais
        if (y == LINHAS - 1 || y == 0)
            dy *= -1;
    }

    return 0;
}
