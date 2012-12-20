/*
  Grafos

  Grafos implementados por meio de matriz de adjacência.

  Criação: 09/10/12
  Autor: Sandro Miccoli

*/


#ifndef GRAFOS_H_
#define GRAFOS_H_

#include "matriz.h"


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
