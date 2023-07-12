#include <stdio.h>
#include "simpson.h"
#include <math.h>

double f(double x);
double g(double x);
double h(double x);

int main(void) {
  for(double tol=0.1;tol>1e-7;tol/=10){
    printf("Integral por Simpson Adaptativa de f: %.16g\n", adaptsimpson(0, 1, f, tol));
  }
  printf("\n");
  for(double tol=0.1;tol>1e-7;tol/=10){
    printf("Integral por Simpson Adaptativa de g: %.16g\n", 2/sqrt(M_PI)*adaptsimpson(0, 3, g, tol));
  }
  printf("\n");
  for(double tol=0.1;tol>1e-7;tol/=10){
    printf("Integral por Simpson Adaptativa de h: %.16g\n", adaptsimpson(0, M_PI/2, h, tol));
  }
  return 0;
}

double f(double x) {
  return x/(sqrt(pow(x,2)+9));
}

double g(double x) { // FALTA A CONSTANTE
  return exp(-pow(x,2));
}

double h(double x) {
  return log(cos(x) + sin(x));
}