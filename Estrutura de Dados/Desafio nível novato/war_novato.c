#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TERRITORIOS 5

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    struct Territorio war_novato[MAX_TERRITORIOS];
    int totalTerritorio = 0;
    int opcao;

    do {
        printf("********************\n");
        printf("**** WAR NOVATO ****\n");
        printf("");
    }
    
}
