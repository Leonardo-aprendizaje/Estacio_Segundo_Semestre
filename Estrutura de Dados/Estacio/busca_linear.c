#include <stdio.h>

int buscaLinear(int lista[], int tamanho, int valor){
    // Começamos um loop do inicío (índice 0) até o fim da lista
    for (int i = 0; i < tamanho; i++){
        // Em cada passo comparamos o elemento atual com o valor que buscamos
        if (lista[i] == valor){
            // Se encontrarmos, retornamos a posição (índice) onde ele está!
            return i;
        }
        
    }
    // Se o loop terminar e não encontrarmos nada, retornamos -1
    return -1;
}