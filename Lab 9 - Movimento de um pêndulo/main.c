#include <stdio.h>
#include "pendulo.h"
#include <math.h>

int main(void) {
  double T1, T2 ,a= M_PI/180, b = 0;
  T1 = periodo(M_PI / 180);
  T2 = periodo_simplificado(M_PI / 180);
  printf("Comparação do período para theta = 1°:\nSolução númerica: T = %.16gs\nFórmula Linearizada: %.16gs\n\n", T1, T2);
  // for(int i=0; i<30; i++) {
  //   T1 = pendulo(0, 0.1, &a, &b);
  //   printf("b = %g\n" ,b);
  // }
  return 0;
}