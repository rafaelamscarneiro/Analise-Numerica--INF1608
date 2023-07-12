#include <stdio.h>
#include "integral.h"
#include <math.h>

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);

int main(void) {
  double d, h=1, i1, i2, i3, i4, i5, i6;
  for(int i=0; i<4; i++){
    d = derivada(f1, 0, h);
    printf("h = %.g\tDerivada: %g\n",h,d);
    h/=10;
  }
  i1 = simpson(f2, 0, 4, 16);
  i2 = simpson(f2, 0, 4, 32);
  printf("\nIntegral f2 para n=16: %g\n",i1);
  printf("Integral f2 para n=32: %g\n",i2);

  i3 = simpson(f3, 1, 3, 16);
  i4 = simpson(f3, 1, 3, 32);
  printf("\nIntegral f3 para n=16: %g\n",i3);
  printf("Integral f3 para n=32: %g\n",i4);

  i5 = simpson(f4, 0, M_PI, 16);
  i6 = simpson(f4, 0, M_PI, 32);
  printf("\nIntegral f4 para n=16: %g\n",i5);
  printf("Integral f4 para n=32: %g\n",i6);

  
  return 0;
}

double f1(double x) {
  return cos(x) - 2*sin(x);
}

double f2(double x) {
  return x/(sqrt(pow(x,2)+9));
}

double f3(double x) {
  return pow(x,2)*log(x);
}

double f4(double x) {
  return pow(x,2)*sin(x);
}