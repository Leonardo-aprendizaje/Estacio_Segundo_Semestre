#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define MAX_STR_LEN 50 // Tamanho Máximo de cada string/texto

#define TAM_MAX 10 // Define o número máximo de itens na lista estática

// Estrutura que representa a lista estática

typedef struct {
    char dados[TAM_MAX][MAX_STR_LEN]; // Matriz: 10 linhas (itens), 50 colunas (caracteres por item)
    int quantidade; // Informa a quantidade de itens armazenados realmente na lista.
} ListaEstatica;

void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char* texto);
void removerListaEstatica(ListaEstatica *lista, const char* texto);
void listarListaEstatica(const ListaEstatica *lista);




