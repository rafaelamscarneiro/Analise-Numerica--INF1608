#include <stdio.h>
#include "simpson.h"
#include <math.h>

double simpson(double a, double b, double (*f)(double x));

double adaptsimpson (double a, double b, double (*f)(double x), double tol) {
  double m, delta;
  m = (a+b)/2;
  delta = simpson(a, b, f) - (simpson(a, m, f) + simpson(m, b, f));
  if(fabs(delta) > 15.0*tol) {
    return adaptsimpson(a, m, f, tol/2) + adaptsimpson(m, b, f, tol/2);
  }
  else{
    return simpson(a, m, f) + simpson(m, b, f) - delta/15.0;
  }
  
}

double simpson(double a, double b, double (*f)(double x)) {
  double h = b-a;
  return (h/6)*(f(a)+4*f(a+(h/2))+f(b));
}