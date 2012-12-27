/*
  Trabalho Prático 4 - Problemas NP-Completo e Programação Paralela

  Encontrar um clique em um grafo

  Criação: 19/12/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "grafos_matriz.h"
#include "clique.h"

int main(int argc, char *argv[]){


    if (argc == 3){ // Nome do arquivo (argv[0]) mais os dois parâmetros

        char entrada[40] = "entrada/";
        char saida[40] = "saida/";
        int k; // Instâncias de matrizes

        Conjunto C, S, P;
        Grafo G;

        strcat(entrada,argv[1]);
        strcat(saida,argv[2]);

        FILE * inp = abreArquivoLeitura(entrada);
        FILE * out = abreArquivoEscrita(saida);

        fscanf(inp, "%d ", &k); // Lê as k instâncias de problemas


        for (int l=0; l<k; l++){


            inicializaGrafo(inp, &G);

            imprimeGrafo(G);

            criaConjuntoVazio(&C, G.N);
            criaConjuntoVazio(&S, G.N);
            criaConjuntoCompleto(&P, G.N);
            BK(&C, &P, &S, &G);

            liberaConjunto(&C);
            liberaConjunto(&S);
            liberaConjunto(&P);

            freeGrafo(G);
        }

        fechaArquivo(inp);
        fechaArquivo(out);

    }
    else{
        printf("Número incorreto de parâmetros. Fazer seguir exemplo:\n\n\t./tp1 input.txt output.txt\n\n"); exit(0);
    }
    return 0;
}
