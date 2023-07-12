#include <stdio.h>
#include "ode.h"
# include <math.h>

double f(double t, double y);
double expected(double t);

int main(void) {
  double esperado, PontoMed, PontoMedAdapt, erro;
  esperado = expected(2.4);
  printf("\nAvaliacao ponto medio:\n");
  for(double h = 0.01; h >= 0.0001; h /= 10) {
    PontoMed = PontoMedio(0, 2.4, h, -1, f);
    erro = fabs(PontoMed - esperado)/esperado;
    printf("h = %.16g:\nesperado = %.16g\nPontoMed = %.16g\nerro = %.16g\n\n", h, esperado, PontoMed, erro);
  }
  printf("\nAvaliacao ponto medio adaptativo:\n");
  for(double h = 0.01; h >= 0.0001; h /= 10) {
    PontoMedAdapt = PontoMedioAdapt(0, 2.4, 0.0001, -1, f, 1.2);
    erro = fabs(PontoMedAdapt - esperado)/esperado;
    printf("h = %.16g:\nesperado %.16g\nPontoMedAdapt = %.16g\nerro = %.16g\n\n", h, esperado, PontoMedAdapt, erro);
  }
  return 0;
}

double f(double t, double y) {
  return t*y + pow(t, 3);
}

double expected(double t) {
  return exp(pow(t,2)/2) - pow(t,2) - 2;
}