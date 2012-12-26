/*
  Grafos

  Grafos implementados por meio de matriz de adjacência.

  Criação: 09/10/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include "grafos_matriz.h"


/*
    Manipulação

*/

// Cria a matriz
void criaMatriz(int col, int lin, Matriz *matriz){
    matriz->col = col;
    matriz->lin = lin;
    matriz->matriz = mallocaMatriz(col, lin);
}

// Maloca todas as linhas e colunas da matriz
int ** mallocaMatriz(int col, int lin){
    int ** matriz;
    matriz = (int **) malloc (col * sizeof(int));
    for (int i = 0; i < col; i++){
        matriz[i] = (int *) malloc (lin * sizeof(int));
    }
    return matriz;
}

// Dá free em todos os vetores alocados pela matriz
void destroiMatriz(Matriz *matriz){
    for (int i = 0; i < matriz->col; i++){
        free(matriz->matriz[i]);
    }
    free(matriz->matriz);
}

/*
    Leitura
*/

// Lê a matriz do arquivo
void leMatriz(FILE * arquivo, Matriz * M1){

    int n;

    // Lê quantidade de vértices
    fscanf(arquivo, "%d", &n);

    criaMatriz(n, n, M1);
    preencheMatriz(arquivo, M1);


}

// Preenche a matriz m com os valores da matriz do arquivo.
void preencheMatriz(FILE * arquivo, Matriz *m){
    int num;

    for (int x=0; x < m->col; x++){
            for (int y=0; y < m->lin; y++){
                fscanf(arquivo,"%d ",&num);
                m->matriz[x][y] = num;
            }
        }

}

// Imprime todos os valores da matriz
void imprimeMatriz(Matriz m){

    for (int x=0; x < m.col; x++){
            for (int y=0; y < m.lin; y++){
                printf("%d ",m.matriz[x][y]);
            }
                printf("\n");
        }
}

// Imprime todos os valores da matriz no arquivo
void imprimeMatrizNoArquivo(FILE * arquivo, Matriz m){
    fprintf(arquivo,"%d %d\n", m.col, m.lin);
    for (int x=0; x < m.col; x++){
            for (int y=0; y < m.lin; y++){
                fprintf(arquivo, "%d ", m.matriz[x][y]);
            }
                fprintf(arquivo,"\n");
        }
}


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
