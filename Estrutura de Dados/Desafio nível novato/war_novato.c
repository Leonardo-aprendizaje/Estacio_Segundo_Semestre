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
        printf("\n********************\n");
        printf("**** WAR NOVATO ****\n");
        printf("********************\n");
        printf("1 - Adicionar Territorio\n");
        printf("2 - Listar Territórios\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();


        switch (opcao) {
            case 1:
                
                
                while (totalTerritorio < MAX_TERRITORIOS) {
                    
                    printf("\n** Cadastrando Território %d **\n", totalTerritorio + 1);
                    
                    printf("\nNome do territótio: ");
                    fgets(war_novato[totalTerritorio].nome, sizeof(war_novato[totalTerritorio].nome), stdin);
                    war_novato[totalTerritorio].nome[strcspn(war_novato[totalTerritorio].nome, "\n")] = '\0';

                    printf("Cor do Exercito: ");
                    fgets(war_novato[totalTerritorio].cor, sizeof(war_novato[totalTerritorio].cor), stdin);
                    war_novato[totalTerritorio].cor[strcspn(war_novato[totalTerritorio].cor, "\n")] = '\0';

                    printf("Quantidade de tropas: ");
                    scanf("%d", &war_novato[totalTerritorio].tropas);
                    limparBufferEntrada();

                    totalTerritorio++;
                    printf("\n✅ Território adicionado com sucesso!\n");

                }// else {
                    printf("\n❌ Limite máximo de territórios atingido (%d).\n", MAX_TERRITORIOS);   
                //}
                break;
            
            case 2:
                if (totalTerritorio == 0) {
                    printf("\nNenhum território cadastrado ainda.\n");

                } else {
                    printf("====================================\n");
                    printf("*- Mapa do Mundo - Estado Atual -*\n");
                    printf("====================================\n");
                    
                    for (int i = 0; i < totalTerritorio; i++) {
                        printf("\nTerritório %d: \n", i + 1);
                        printf(" - Nome: %s\n", war_novato[i].nome);
                        printf(" - Dominado por: Exercito %s\n", war_novato[i].cor);
                        printf(" - Tropas: %d\n", war_novato[i].tropas);
                    }
                }
            break;
            default:
                printf("\nOpção invalida. Tente novamente.\n");

                break;
        }
        
    } while (opcao != 3);
    
    return 0;
}
