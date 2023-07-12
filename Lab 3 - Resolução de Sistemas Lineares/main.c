#include <stdio.h>
#include <stdlib.h>
#include "sistlinear.h"

int main() {
    int n = 3;
    double **A;
    double l1[3] = {1, -1, 0}, l2[3]={-1, 2, 1}, l3[3]={0,1,2}; // Inicializa linhas da matriz
    double x[n], b[3] = {0,2,3}; // Inicializa vetores 
    A = (double**) malloc(n*sizeof(double*));
    A[0] = l1; A[1] = l2; A[2] = l3; // Colocando linhas na matriz
    /* Imprimir a matriz criada
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("A[i][j] = %lf ", A[i][j]);
        }
        printf("\n");
    }*/
    gauss(3, A, b, x);
    printf("(1) Resultado do sistema linear:\n");
    for(int i=0; i<n; i++){
        printf("x[%d] = %g ",i,x[i]);
    }
    printf("\n\n");
    double **M = (double**)malloc(6*sizeof(double*));
    //Declarando cada linha da matriz:
    double j1[6] = {3,-1,0,0,0,0.5}, j2[6] = {-1,3,-1,0,0.5,0}, j3[6] = {0,-1,3,-1,0,0},j4[6] = {0,0,-1,3,-1,0},j5[6] = {0,0.5,0,-1,3,-1},j6[6] = {0.5,0,0,0,-1,3};
    //Colocando cada linha na matriz: (as linhas 1 e 3 estão invertidas p testar pivotamento)
    M[0] = j3; M[1] = j2;M[2] = j1;M[3] = j4;M[4] = j5;M[5] = j6;
    double y[6]; // vetor das icognitas
    double v[6] = {1, 1.5, 2.5, 1,1.5, 2.5}; // vetor resultado, com as linhas 1 e 3 invertidas p testar pivotamento
   
   /* Imprimir a matriz 
    printf("\n");
    for(int i=0; i<6; i++){
        //printf("x= %g ",x[i]);
        for(int j=0; j<6; j++){
            printf("%g ", M[i][j]);
        }
        printf("\n");
    }*/
    gauss(6, M, v, y);
    printf("(2) Resultado do sistema linear:\n");
    for(int i=0;i<6;i++){
        printf("y[%d] = %g ",i,y[i]);
    }
     return 0;
}