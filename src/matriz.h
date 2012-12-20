/*
  Módulo de manipulação de matrizes alocando a memória dinâmicamente

  Funções de inserção, leitura, impressão e outras manipulações.

  Criação: 09/10/12
  Autor: Sandro Miccoli

*/

#ifndef MATRIZ_H_
#define MATRIZ_H_

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

#endif /* MATRIZ_H_ */
