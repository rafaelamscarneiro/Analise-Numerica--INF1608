#include <stdio.h>
#include <stdlib.h>
#include "gradconj.h"

int main(void) {
  double tol = 1e-7, n;
  double x0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  double b[] = {1.4, 2.8, 3.8, 4.8, 5.8, 6.8, 7.8, 8.8, 9.8, 10.4};
  double l0[] = {1.0, 0.4, 0, 0, 0, 0, 0, 0, 0, 0};
  double l1[] = {0.4, 2, 0.4, 0, 0, 0, 0, 0, 0, 0};
  double l2[] = {0, 0.4, 3.0, 0.4, 0, 0, 0, 0, 0, 0};
  double l3[] = {0, 0, 0.4, 4, 0.4, 0, 0, 0, 0 , 0};
  double l4[] = {0, 0, 0, 0.4, 5.0, 0.4, 0, 0, 0, 0};
  double l5[] = {0, 0, 0, 0, 0.4, 6.0, 0.4, 0, 0 , 0};
  double l6[] = {0, 0, 0, 0, 0, 0.4, 7, 0.4, 0, 0};
  double l7[] = {0, 0, 0, 0, 0, 0, 0.4, 8, 0.4, 0};
  double l8[] = {0, 0, 0, 0, 0, 0, 0, 0.4, 9, 0.4};
  double l9[] = {0, 0, 0, 0, 0, 0, 0, 0, 0.4, 10};
  double* A[] = {l0, l1, l2, l3, l4, l5, l6, l7, l8, l9};
  
  int num_iter;
  
  n = 10;
  num_iter = gradconj(n, A, b, x0, tol);
  printf("Vetor solução esperado:\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n\nVetor solução utilizando o método Gradientes Conjugados:\n\n");
  for(int i=0; i<n; i++) {
    printf("x0[%d] = %.16g\n", i, x0[i]);
  }
  printf("\nNúmero de iterações: %d\n", num_iter);
  return 0;
}