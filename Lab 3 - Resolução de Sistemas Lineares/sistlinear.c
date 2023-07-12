#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sistlinear.h"

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