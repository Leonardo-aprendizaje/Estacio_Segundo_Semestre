#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// --------------------
// STRUCT DO ITEM
// --------------------
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// --------------------
// PROTÓTIPOS DAS FUNÇÕES
// --------------------
void inserirItem(struct Item mochila[], int *total);
void removerItem(struct Item mochila[], int *total);
void listarItens(struct Item mochila[], int total);
void buscarItem(struct Item mochila[], int total);
void limparBuffer();

// --------------------
// FUNÇÃO PRINCIPAL
// --------------------
int main() {
    struct Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== SISTEMA DE INVENTÁRIO =====\n");
        printf("1 - Cadastrar Item\n");
        printf("2 - Remover Item\n");
        printf("3 - Listar Itens\n");
        printf("4 - Buscar Item\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                inserirItem(mochila, &total);
                listarItens(mochila, total);
                break;
            case 2:
                removerItem(mochila, &total);
                listarItens(mochila, total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                buscarItem(mochila, total);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}

// --------------------
// FUNÇÃO PARA LIMPAR BUFFER
// --------------------
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// --------------------
// INSERIR ITEM NA MOCHILA
// --------------------
void inserirItem(struct Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nA mochila está cheia!\n");
        return;
    }

    printf("\n--- Cadastro de Item ---\n");

    printf("Nome do item: ");
    fgets(mochila[*total].nome, 30, stdin);
    mochila[*total].nome[strcspn(mochila[*total].nome, "\n")] = '\0';

    printf("Tipo (arma, munição, cura...): ");
    fgets(mochila[*total].tipo, 20, stdin);
    mochila[*total].tipo[strcspn(mochila[*total].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    limparBuffer();

    (*total)++;

    printf("\nItem adicionado com sucesso!\n");
}

// --------------------
// REMOVER ITEM PELO NOME
// --------------------
void removerItem(struct Item mochila[], int *total) {
    if (*total == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char nomeRemover[30];
    printf("\nNome do item a remover: ");
    fgets(nomeRemover, 30, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            // substituir pelo último
            mochila[i] = mochila[*total - 1];
            (*total)--;

            printf("\nItem removido com sucesso!\n");
            return;
        }
    }

    printf("\nItem não encontrado!\n");
}

// --------------------
// LISTAR ITENS DA MOCHILA
// --------------------
void listarItens(struct Item mochila[], int total) {
    printf("\n=== ITENS NA MOCHILA (%d) ===\n", total);

    if (total == 0) {
        printf("Nenhum item cadastrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

// --------------------
// BUSCA SEQUENCIAL POR NOME
// --------------------
void buscarItem(struct Item mochila[], int total) {
    if (total == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\nBuscar item por nome: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n--- Item encontrado! ---\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("\nItem não encontrado.\n");
}
