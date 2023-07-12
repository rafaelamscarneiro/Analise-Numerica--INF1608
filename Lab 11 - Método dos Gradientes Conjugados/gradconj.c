#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gradconj.h"

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
  free(Ax);
  free(residuo);
  return norma;
}

double prod_escalar(int n, double *u, double *v) {
  double w = 0;
  for(int i=0; i<n; i++) {
    w += u[i]*v[i];
  }
  return w;
}

int gradconj (int n, double** A, double* b, double* x, double tol) {
  int cont;
  double norma_2, d[n], r[n], Ad[n], alfa, beta, r_ant[n];
  norma_2 = norma_2_residuo(n, A, b, x); 
  /* Matriz Ax usada para calcular os vetores d0 e r0 (código do lab de mmq)*/
  double* Ax = (double*)malloc(n*sizeof(double)); 
  for(int i=0; i<n; i++){
    Ax[i] = 0;
    for(int j=0; j<n; j++) {
      Ax[i] += A[i][j] * x[j];
    }
  }
  for(int i=0; i<n; i++) {
    d[i] = b[i] - Ax[i];
    r[i] = b[i] - Ax[i];
  }
  cont = 0;
  while(norma_2 > tol) {
    for(int i=0; i<n; i++) { // guardando rk 
      r_ant[i] = r[i];
    }
    /* Fazendo A * dk*/
    for(int i=0; i<n; i++) {
      Ad[i] = 0;
      for(int j=0; j<n; j++) {
        Ad[i] += A[i][j] * d[j];
      }
    }
    alfa = prod_escalar(n, r, r)/prod_escalar(n, d, Ad);
    
    for(int i=0; i<n; i++) {
      x[i] += alfa*d[i];
      r[i] -= alfa*Ad[i];
    }
    beta = prod_escalar(n, r, r)/prod_escalar(n, r_ant, r_ant);
    for(int i=0; i<n; i++) {
      d[i] = r[i] + beta*d[i];
    }
    double norma = 0;
    for(int i=0; i<n; i++){
      norma += pow(r[i],2);
    }
    norma_2 = sqrt(norma);
    cont++;
  }
  free(Ax);
  return cont;
}


