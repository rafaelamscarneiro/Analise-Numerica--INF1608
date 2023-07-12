#include <stdio.h>
#include "integral.h"

double derivada (double (*f) (double x), double x, double h) {
  return (f(x+h) - f(x-h))/(2*h);
}

double simpson (double (*f) (double), double a, double b, int n) {
  double h, soma, ini;
  h = (b-a)/n;
  ini=a;
  soma=0;
  for(int i=0; i<n; i++) {
    soma += h/6*(f(ini) + 4*f(ini + h/2) + f(ini + h));
    ini+=h;
  }
  return soma;
}

