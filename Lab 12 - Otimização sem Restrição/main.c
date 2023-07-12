#include <stdio.h>
#include <math.h>
#include "otimizacao.h"

double f(double x);
double g(double x);

int main(void) {
  double r, delta, *xmin;
  int num_iter;

  printf("f(x) = x^2 + sin(x)\nValor esperado de fmin(x): -0.45018361\n");
  r = -0.6;
  delta = r/2;
  num_iter = mips(r, delta, f, xmin);
  printf("r = %.2g:\nValor obtido pelo método: %.16g\nNumero de iteracoes: %d\n", r, *xmin, num_iter);
  
  r = 8;
  delta = r/2;
  num_iter = mips(r, delta, f, xmin);
  printf("r = %.2g:\nValor obtido pelo método: %.16g\nNumero de iteracoes: %d\n\n", r, *xmin, num_iter);

  printf("g(x) = x^6 - 11x^3 + 17x^2 - 7x + 1\nValor esperado de gmin(x): 0.283648358197644\n");
  r = 0.3;
  delta = r/3;
  num_iter = mips(r, delta, g, xmin);
  printf("r = %.2g:\nValor obtido pelo método: %.16g\nNumero de iteracoes: %d\n",r,*xmin, num_iter);
  r = 0.8;
  delta = r/4;
  num_iter = mips(r, delta, g, xmin);
  printf("r = %.2g:\nValor obtido pelo método: %.16g\nNumero de iteracoes: %d\n",r,*xmin, num_iter);
  r = -1;
  delta = r/2;
  num_iter = mips(r, delta, g, xmin);
  printf("r = %.2g:\nValor obtido pelo método: %.16g\nNumero de iteracoes: %d\n\n",r,*xmin, num_iter);
  return 0;
}

double f(double x) {
  return pow(x,2) + sin(x);
}

double g(double x) {
  return (pow(x,6) - 11*pow(x,3) + 17*pow(x,2) - 7*x + 1);
}