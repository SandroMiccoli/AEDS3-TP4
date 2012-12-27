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

void criaConjuntoVazio(Conjunto * C, int tam){
    C->tam = tam;

    C->qtde = 0;

    C->elementos = (int *) malloc (tam * sizeof(int));

    for (int i=0; i<tam; i++){
        C->elementos[i] = 0;
    }
}

void criaConjuntoCompleto(Conjunto * C, int tam){
    C->tam = tam;

    C->qtde = tam;

    C->elementos = (int *) malloc (tam * sizeof(int));

    for (int i=0; i<tam; i++){
        C->elementos[i] = 1;
    }
}

void liberaConjunto(Conjunto * C){
    free(C->elementos);
}

void insereElemento(Conjunto *C, int elemento){

    C->qtde++;

    if (elemento < C->tam)
        C->elementos[elemento] = 1;

}

void removeElemento(Conjunto *C, int elemento){


    if (elemento < C->tam)
        C->elementos[elemento] = 0;

    C->qtde--;

    printf("Removeu %d\n",C->qtde);

}

int confereVazio(Conjunto * C){
    if (C->qtde==0) return 0;

    for (int i=0; i<C->tam; i++){
        if (C->elementos[i] == 1) return 0;
    }
    return 1;
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

void intersecaoVizinhos(Conjunto * P, Grafo * G, int vertice){

    for (int i=0; i < G->N; i++){
        if ((G->matrizAdj.matriz[vertice][i] == 1 && P->elementos[i] == 0) || (G->matrizAdj.matriz[vertice][i] == 0 && P->elementos[i] == 1)){
            printf("P: "); removeElemento(P, i);
        }

    }
}

void BK(Conjunto * C, Conjunto * P, Conjunto * S, Grafo * G){


    if (confereVazio(P) && confereVazio(S)){
        printf("Maior Clique: %d\n",C->qtde);
        imprimeConjunto(*C);
        //return;
    }

    for (int v=0; v<P->tam && P->elementos[v] == 1; v++){

        intersecaoVizinhos(P, G, v);
        intersecaoVizinhos(S, G, v);
        //printf("DEBUG!\n");

        insereElemento(C,v);
        BK(C,P,S,G);

        printf("P: "); removeElemento(P, v);
        printf("S: "); removeElemento(S, v);
    }


}
