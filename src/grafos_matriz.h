
#ifndef GRAFOS_H_
#define GRAFOS_H_

/*
  Módulo de manipulação de matrizes alocando a memória dinâmicamente

  Funções de inserção, leitura, impressão e outras manipulações.

  Criação: 09/10/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz{
    int col, lin;
    int ** matriz;
} Matriz;

// Manipulação
void criaMatriz(int col, int lin, Matriz *matriz);

int ** mallocaMatriz(int col, int lin);

void destroiMatriz(Matriz *matriz);


// Leitura e Escrita
void leMatriz(FILE * arquivo, Matriz * M1);

void preencheMatriz(FILE * arquivo, Matriz * m);

void imprimeMatriz(Matriz m);

void imprimeMatrizNoArquivo(FILE * arquivo, Matriz m);

/*
  Grafos

  Grafos implementados por meio de matriz de adjacência.

  Criação: 09/10/12
  Autor: Sandro Miccoli

*/



// Estrutura básica de um grafo, contendo seu número de vértices, arestas e um ponteiro para sua matriz de adjacência.
typedef struct grafo {
    Matriz matrizAdj;
    int N; // Quantidade de vértices no grafo
} Grafo;

// Inicializa grafo
void inicializaGrafo(FILE * arquivo, Grafo * G);

// Imprime o grafo
void imprimeGrafo(Grafo G);

// Limpa o grafo da memória
void freeGrafo(Grafo G);



#endif /* GRAFOS_H_ */
