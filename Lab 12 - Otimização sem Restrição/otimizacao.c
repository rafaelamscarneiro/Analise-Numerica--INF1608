#include <stdio.h>
#include <math.h>
#include "otimizacao.h"

int mips (double r, double delta, double (*f) (double x), double* xmin) {
  double s, t, d;
  int cont = 0;
  s = r - delta;
  t = r + delta;
  while((fabs(f(s) - f(t)) > 1E-6) || (cont < 4)) {
    
    if(cont > 50) {
      return 0;
    }
    d = 2*((s-r)*(f(t)-f(s))-(f(s)-f(r))*(t-s));
    if(d < 1E-10) {
      *xmin = (r+s+t)/3;
    }
    else {
      *xmin = (r+s)/2 - ((f(s)-f(r))*(t-r)*(t-s))/d;
    }
    r = s;
    s = t;
    t = *xmin;
    cont++;
  }
  *xmin = (s+t)/2;
  return cont;
}