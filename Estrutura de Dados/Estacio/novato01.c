#include <stdio.h>

typedef struct  {
    char nome[50];
    int idade;
    float media;
} Aluno;

int main(){
    Aluno aluno1 = {"Leonardo", 20, 10,0};

    printf("Aluno: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Média: %.1f", aluno1.media);

    return 0;
}

