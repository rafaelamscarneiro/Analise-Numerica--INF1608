#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raiz.h"

double f(double x) {
    double g=9.8, v=35, t=9, c=15;
    double r = v - g*x/c*(1-exp(-c/x*t));
    return  r;
}

int main()
{
    
    double a=0, b=200, r, x;
    int i;
    i = bissecao(a, b, f, &r);
    printf("Numero de iteracoes = %d\n",i);
    printf("Raiz = %.16g\n", r);

    return 0;
}