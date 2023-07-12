#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raiz.h"



int bissecao (double a, double b, double (*f) (double x), double* r){
    double e;
    double c;
    if(f(a) * f(b) >= 0) {
        return 0;
    }
    e = (b-a) / 2;
    int cont=0;
    while(e > 0.5E-8) {
        cont++;
        e = (b-a) / 2;
        c = (a+b) / 2;
        if(fabs(f(c)) < 1E-12) {
            *r = c;
            return c;
        } 
        if(f(a)*f(c) < 0) {
            b = (a+b) / 2;;
        }
        else {
            a = (a+b) / 2;;
        }
        
        
    }
    *r = c;
    return cont;
    
    
}
