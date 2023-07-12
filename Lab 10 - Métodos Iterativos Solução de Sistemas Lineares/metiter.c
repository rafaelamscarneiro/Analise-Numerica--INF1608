#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "metiter.h"

double norma_2_residuo(int n, double **A, double *b, double *x) {
  double* Ax = (double*)malloc(n*sizeof(double));
  for(int i=0; i<n; i++){
    Ax[i] = 0;
    for(int j=0; j<n; j++) {
      Ax[i] += A[i][j] * x[j];
    }
  }
  double* residuo =  (double*)malloc(n*sizeof(double));
  for(int i=0; i<n; i++) {
    residuo[i] = b[i] - Ax[i];
  }
  double norma = 0;
  for(int i=0; i<n; i++){
    norma += pow(residuo[i],2);
  }
  norma = sqrt(norma);
  return norma;
}

int gauss_seidel (int n, double** A, double* b, double* x, double tol) {
  double soma, norma_2, cont=0;
  norma_2 = norma_2_residuo(n, A, b, x);
  
  while(norma_2 > tol) {
    for(int i=0; i<n; i++) {
      soma=0;
      for(int j=0; j<n; j++) {
        if(i != j) {
          soma += A[i][j] * x[j];
        }
      }
      x[i] = (b[i] - soma)/A[i][i];
    }
    //printf("cont");
    cont++;
    norma_2 = norma_2_residuo(n, A, b, x);
  }
  return cont;
}

int sor_gauss_seidel (int n, double** A, double* b, double* x, double tol, double w) {
  double soma, norma_2, cont=0, *aux;
  norma_2 = norma_2_residuo(n, A, b, x);
  aux = (double*) malloc(n*sizeof(double));
  while(norma_2 > tol) {
    for(int i=0; i<n; i++) {
      aux[i] = x[i];
    }
    for(int i=0; i<n; i++) {
      soma=0;
      for(int j=0; j<n; j++) {
        if(i != j) {
          soma += A[i][j] * x[j];
        }
      }
      x[i] = (b[i] - soma)/A[i][i];
    }
    for(int i=0; i<n; i++) {
      x[i] = (1-w)*aux[i] + w*x[i];
    }
    
    //printf("cont");
    cont++;
    norma_2 = norma_2_residuo(n, A, b, x);
  }
  return cont;
}


