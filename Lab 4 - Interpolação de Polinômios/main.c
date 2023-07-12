#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interp.h"

double f(double x) {
  double mi = 0.0, sigma = 0.5, res;
  res =1.0/(sigma*sqrt(2.0*M_PI))*exp(-(pow((x-mi)/sigma, 2))/2);
  return res;
}

int main(void) {
  int n=10;
  double *xi, *bi;
  xi = (double*) malloc(n*sizeof(double));
  regular(n, -3, 3, xi);
  bi = (double*) malloc(n*sizeof(double));
  coeficientes(n, xi, f, bi);
  printf("Comparacao funcao e interpolacao com amostras regulares:\n");
  for(int i=0; i<n; i++){
    printf("f(%g) = %g - Avalia(%g) = %g\n", xi[i], f(xi[i]), xi[i], avalia(n, xi, bi, xi[i]));
  }
  chebyshev(n, -3, 3, xi);
  coeficientes(n, xi, f, bi);
  printf("\nComparacao funcao e interpolacao com amostras de Chebyshev:\n");
  for(int i=0; i<n; i++){
    printf("f(%g) = %g - Avalia(%g) = %g\n", xi[i], f(xi[i]), xi[i], avalia(n, xi, bi, xi[i]));
  }
  return 0;
}