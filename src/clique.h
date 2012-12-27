#ifndef CLIQUE_H_
#define CLIQUE_H_

/*

  Clique

  Módulo de manipulação de grafos para encontrar cliques.

  Criação: 26/12/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "grafos_matriz.h"


/*
    Funções relativas à conjuntos

*/
typedef struct conjunto {
    int * elementos;
    int tam;
    int qtde;
} Conjunto;

void criaConjuntoVazio(Conjunto * C, int tam);

void criaConjuntoCompleto(Conjunto * C, int tam);

void liberaConjunto(Conjunto * C);

void insereElemento(Conjunto *C, int elemento);

void imprimeConjunto(Conjunto C);

void insereElemento(Conjunto * C, int elemento);

void removeElemento(Conjunto * C, int elemento);

int confereVazio(Conjunto * C);


/*
    Funções da Clique e do algortimo Bron-Kerbosch

*/

int confereClique(Grafo * G);

void intersecaoVizinhos(Conjunto * P, Grafo * G, int vertice);

void BK(Conjunto * C, Conjunto * P, Conjunto * S, Grafo * G);

#endif /* CLIQUE_H_ */
