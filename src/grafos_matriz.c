/*
  Grafos

  Grafos implementados por meio de matriz de adjacência.

  Criação: 09/10/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "grafos_matriz.h"
#include "matriz.h"

// Inicializa o grafo
void inicializaGrafo(FILE * arquivo, Grafo * G){

   leMatriz(arquivo, &(G->matrizAdj)); // Lê matrizes do arquivo e as insere na variável de matrizAjd

   G->N = G->matrizAdj.col;  // Atribui a quantidade N de cidades no grafo


};

// Imprime o grafo
void imprimeGrafo(Grafo G){

    //Imprime número de vértices
    printf("%d\n",G.N);

    imprimeMatriz(G.matrizAdj);


};


void freeGrafo(Grafo G){

    destroiMatriz(&(G.matrizAdj));


}
