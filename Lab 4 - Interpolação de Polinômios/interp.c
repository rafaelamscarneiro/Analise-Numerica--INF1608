#include <stdio.h>
#include <math.h>
#include "interp.h"

void regular (int n, double a, double b, double* xi) {
  xi[0] = a;
  double dif = (b-a)/(n-1);  
  for(int i=1; i<n; i++) {
    xi[i] = xi[i-1] + dif;
  }
}

void chebyshev (int n, double a, double b, double* xi) {
  int beta=1;
  for(int i=0; i<n; i++) {
    xi[i] = (b-a)/2*cos(beta*M_PI/(2*n)) + (a+b)/2;
    beta+=2;
  }
}

void coeficientes (int n, double* xi, double (*f) (double), double* bi) {
  bi[0] = f(xi[0]);
  if(n>1) {
    bi[1] = (f(xi[1] - f(xi[0]))/(xi[1]-xi[0]));
    for(int i=2; i<n; i++) {
      bi[i] = (( (f(xi[i]) - f(xi[i-1])) / (xi[i] - xi[i-1]) ) - bi[i-1]) / (xi[i] - xi[0]);
    }
  }
}

double avalia (int n, double* xi, double* bi, double x) {
  double soma = bi[0], coef;
  for(int i=1; i<n; i++) {
    coef=bi[i];
    for(int j=1; j<i; j++) {
      coef*=(x-xi[j]);
    }
    soma+=coef;
  }
  return soma;
}