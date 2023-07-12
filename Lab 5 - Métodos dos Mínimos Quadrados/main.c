#include <stdio.h>
#include <stdlib.h>
#include "mmq.h"

int main(void) {
  double** A = (double**) malloc(5*sizeof(double*));
  double a0[3] = {3, -1, 2};
  double a1[3] = {4, 1, 0};
  double a2[3] = {-3, 2, 1};
  double a3[3] = {1, 1, 5};
  double a4[3] = {-2, 0, 3};
  A[0] = a0;
  A[1] = a1;
  A[2] = a2;
  A[3] = a3;
  A[4] = a4;
  double b[5] = {10, 10, -5, 15, 0};
  double* x = (double*)malloc(3*sizeof(double));

  double norma = mmq (5, 3, A, b, x);
  printf("Primeiro sistema:\n");
  for(int i=0; i<3; i++) {
    printf("x[%d] = %.16g\n", i, x[i]);
  }
  printf("erro = %.16g\n", norma);
  
  double** M = (double**) malloc(5*sizeof(double*));

  double b0[4] = {4, 2, 3, 0};
  double b1[4] = {-2, 3, -1, 1};
  double b2[4] = {1, 3, -4, 2};
  double b3[4] = {1, 0, 1, -1};
  double b4[4] = {3, 1, 3, -2};
  //double* M[5] = {b0, b1, b2, b3, b4};
  M[0] = b0;
  M[1] = b1;
  M[2] = b2;
  M[3] = b3;
  M[4] = b4;
  double c[5] = {10, 0, 2, 0, 5};

  double* y = (double*)malloc(4*sizeof(double));
  double norma_2 = mmq(5, 4, M, c, y);

  printf("\nSegundo sistema:\n");
  for(int i=0; i<4; i++) {
    printf("y[%d] = %.16g\n", i, y[i]);
  }
  printf("erro = %.16g\n", norma_2);
  
  return 0;
}