#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mmq.h"

void gauss (int n, double** a, double* b, double* x); // Lab 3

double** transposta(double** M, int m, int n) {
  double** T = (double**) malloc(n*sizeof(double*));
  for(int j=0; j<n; j++) {
    T[j] = (double*) malloc(m*sizeof(double));
    for(int i=0; i<m; i++) {
      T[j][i] = M[i][j];
    }
  }
  return T;
}

double** multiplica(double** A, double** B, int m, int n) {
  double** R = (double**) malloc(m*sizeof(double*));
  for(int i=0; i<m; i++) {
    R[i] = (double*) malloc(m*sizeof(double));
    for(int j=0; j<m; j++){
      R[i][j] = 0;
      for(int k=0; k<n; k++) {
        R[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return R;
}

double mmq (int m, int n, double** A, double* b, double* x) {
  double** A_T = transposta(A, m, n);
  double** R = multiplica(A_T, A, n, m);
  double* novo_b = (double*)malloc(n*sizeof(double));
  for(int i=0; i<n; i++) {
    novo_b[i] = 0;
    for(int j=0; j<m; j++){
      novo_b[i] += A_T[i][j] * b[j]; 
    }
  }
  
  gauss(n, R, novo_b, x);

  double* Ax = (double*)malloc(m*sizeof(double));
  for(int i=0; i<m; i++){
    Ax[i] = 0;
    for(int j=0; j<n; j++) {
      Ax[i] += A[i][j] * x[j];
    }
  }
  double* residuo =  (double*)malloc(m*sizeof(double));
  for(int i=0; i<m; i++) {
    residuo[i] = b[i] - Ax[i];
  }
  double norma = 0;
  for(int i=0; i<m; i++){
    norma += pow(residuo[i],2);
  }
  norma = sqrt(norma);
  return norma;
}

// Lab 3:
void gauss (int n, double** a, double* b, double* x)
{
  for (int j=0; j<n-1; ++j) {
    // implementa pivotamento
    // ...
    
    int k=j;
    double *aux, elem;
    for(int k=j+1; k<n-1; k++) {
        if(fabs(a[k][j]) > fabs(a[j][j])) {
            aux = a[j];
            a[j] = a[k];
            a[k] = aux;
            elem = b[j];
            b[j] = b[k];
            b[k] = elem;
        }
    }
    // transformacao da matriz
    for (int i=j+1; i<n; ++i) {
      double f = a[i][j]/a[j][j];
      for (int k=j; k<n; ++k)
        a[i][k] -= f*a[j][k];
      b[i] -= f*b[j];
    }
  }
  // substituicao regressiva
  // ...
  double soma;
  n--;
  x[n] = b[n]/a[n][n];
  for(int i = n-1; i>=0; i--) {
    soma = 0;
    for(int j=i+1; j<=n; j++) {
      soma += a[i][j]*x[j];
    }
    x[i] = (b[i] - soma)/a[i][i];
  }
  
    
}