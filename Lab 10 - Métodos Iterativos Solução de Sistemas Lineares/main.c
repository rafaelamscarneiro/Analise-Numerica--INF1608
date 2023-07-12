#include <stdio.h>
#include "metiter.h"
#include <stdlib.h>

int main(void) {
  double tol = 1e-7;
  double **A;
  double xa[2] = {0, 0}, ba[2] = {5, 5};
  double xa1[2] = {0, 0};
  int num_iter;
  
  A = (double**)malloc(2*sizeof(double*));
  for(int i=0; i<2; i++) {
    A[i] = (double*)malloc(2*sizeof(double));
  }
  A[0][0] = 3; A[0][1] = 1;
  A[1][0] = 1; A[1][1] = 2;

  num_iter = gauss_seidel(2, A, ba, xa, tol);
  printf("Teste 1: x esperado = {1, 2}\n\n");
  printf("Gauss Seidel:\n");
  for(int i=0; i<2; i++) {
    printf("x[%d] = %.16g\n", i, xa[i]);
  }
  printf("Numero de iteracoes: %d\n\n", num_iter);
  printf("Gauss Seidel com sobre-relaxamento:\n");
  num_iter = sor_gauss_seidel(2, A, ba, xa1, tol, 1.1);
  for(int i=0; i<2; i++) {
    printf("x[%d] = %.16g\n", i, xa1[i]);
  }
  printf("Numero de iteracoes: %d\n\n****************\n\n", num_iter);
  
  double **B;
  double xb[6] = {0, 0, 0, 0, 0, 0}, bb[6] = {2.5, 1.5, 1, 1, 1.5, 2.5};
  double xb1[6] = {0, 0, 0, 0, 0, 0};
  B = (double**) malloc(6*sizeof(double*));
  for(int i=0; i<6; i++) {
    B[i] = (double*)malloc(6*sizeof(double));
  }
  double l1[6] = {3, -1, 0, 0, 0, 0.5};
  double l2[6] = {-1, 3, -1, 0, 0.5, 0};
  double l3[6] = {0, -1, 3, -1, 0, 0};
  double l4[6] = {0, 0, -1, 3, -1, 0};
  double l5[6] = {0, 0.5, 0, -1, 3, -1};
  double l6[6] = {0.5, 0, 0, 0, -1, 3};
  B[0] = l1;
  B[1] = l2;
  B[2] = l3;
  B[3] = l4;
  B[4] = l5;
  B[5] = l6;
  num_iter = gauss_seidel(6, B, bb, xb, tol);
  printf("Teste 2: x esperado = {1, 1, 1, 1, 1, 1}\n\n");
  printf("Gauss Seidel:\n");
  for(int i=0; i<6; i++) {
    printf("x[%d] = %.16g\n", i, xb[i]);
  }
  printf("Numero de iteracoes: %d\n\n", num_iter);
  printf("Gauss Seidel com sobre-relaxamento:\n");
  num_iter = sor_gauss_seidel(6, B, bb, xb1, tol, 1.1);
  for(int i=0; i<6; i++) {
    printf("x[%d] = %.16g\n", i, xb1[i]);
  }
  printf("Numero de iteracoes: %d\n\n****************\n\n", num_iter);
  
  return 0;
}