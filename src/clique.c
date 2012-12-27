/*

  Clique

  Módulo de manipulação de grafos para encontrar cliques.

  Criação: 26/12/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "clique.h"
#include "grafos_matriz.h"


/*
    Funções relativas à conjuntos
*/

void criaConjunto(Conjunto * C, int tam){
    C->tam = tam;

    C->elementos = (int *) malloc (tam * sizeof(int));

    for (int i=0; i<tam; i++){
        C->elementos[i] = i;
    }
}

void liberaConjunto(Conjunto * C){
    free(C->elementos);
}

void imprimeConjunto(Conjunto C){
    for (int i=0; i<C.tam; i++){
        printf("%d ",C.elementos[i]);
    }
    printf("\n");
}

/*
    Funções da Clique e do algortimo Bron-Kerbosch

*/

int confereClique(Grafo * G){
    int i, j;

    for(i = 0; i < G->N; i++){
        for(j = 0; j < G->N; j++){
            if(i != j && G->matrizAdj.matriz[i][j] == 0) return 0;
        }
    }
    return 1;
}

void BK(Conjunto C, Conjunto P, Conjunto S){
    printf("ok");
}
