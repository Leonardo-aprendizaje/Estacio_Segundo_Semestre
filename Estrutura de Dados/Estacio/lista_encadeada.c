#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// =============================
//   ESTRUTURA DO NÓ
// =============================
struct No {
    int dado;
    struct No* proximo;
};

// =============================
//   CRIAR NÓ
// =============================
struct No* criarNo(int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    if (novo == NULL) {
        printf("Erro: sem memória!\n");
        exit(1);
    }
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

// =============================
//   INSERIR NO INÍCIO
// =============================
void inserirInicio(struct No** inicio, int valor) {
    struct No* novo = criarNo(valor);
    novo->proximo = *inicio;
    *inicio = novo;
}

// =============================
//   INSERIR NO FIM
// =============================
void inserirFim(struct No** inicio, int valor) {
    struct No* novo = criarNo(valor);

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    struct No* atual = *inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
}

// =============================
//   BUSCAR ELEMENTO
// =============================
int buscaLinearLista(struct No* inicio, int valor) {
    int pos = 0;
    struct No* atual = inicio;

    while (atual != NULL) {
        if (atual->dado == valor)
            return pos;

        atual = atual->proximo;
        pos++;
    }
    return -1; // não encontrado
}

// =============================
//   REMOVER POR VALOR
// =============================
bool removerValor(struct No** inicio, int valor) {
    if (*inicio == NULL) return false;

    struct No* atual = *inicio;
    struct No* anterior = NULL;

    // Se for o primeiro nó
    if (atual->dado == valor) {
        *inicio = atual->proximo;
        free(atual);
        return true;
    }

    // Busca o nó a ser removido
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return false; // não achou

    anterior->proximo = atual->proximo;
    free(atual);
    return true;
}

// =============================
//   IMPRIMIR LISTA
// =============================
void imprimirLista(struct No* inicio) {
    printf("Lista: ");
    while (inicio != NULL) {
        printf("%d -> ", inicio->dado);
        inicio = inicio->proximo;
    }
    printf("NULL\n");
}

// =============================
//   LIBERAR MEMÓRIA DA LISTA
// =============================
void liberarLista(struct No** inicio) {
    struct No* atual = *inicio;
    while (atual != NULL) {
        struct No* prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}

// =============================
//   FUNÇÃO PRINCIPAL (DEMO)
// =============================
int main() {
    struct No* lista = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 5);
    inserirFim(&lista, 20);
    inserirFim(&lista, 30);

    imprimirLista(lista);

    int busca = 20;
    int pos = buscaLinearLista(lista, busca);

    if (pos != -1)
        printf("Valor %d encontrado na posição %d\n", busca, pos);
    else
        printf("Valor %d não encontrado!\n", busca);

    removerValor(&lista, 10);
    imprimirLista(lista);

    liberarLista(&lista);

    return 0;
}
