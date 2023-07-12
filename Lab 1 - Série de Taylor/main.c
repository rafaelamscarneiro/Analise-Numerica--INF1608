#include <stdio.h>
#include <math.h>
#include "taylor.h"

int main(){
    int i;
    for( i=2; i<6; i++){
        printf("Avaliando com %d termos:\n", i);
        double d0 = avalia_cosseno(i, M_PI/10);
        printf("Taylor = %lf; Cos = %lf\t", d0, cos(M_PI/10));
        double d1 = avalia_cosseno(i, M_PI/8);
        printf("Taylor = %lf; Cos = %lf\t", d1, cos(M_PI/8));
        double d2 = avalia_cosseno(i, M_PI/6);
        printf("Taylor = %lf; Cos = %lf\t", d2, cos(M_PI/6));
        double d3 = avalia_cosseno(i, M_PI/4);
        printf("Taylor = %lf; Cos = %lf\t", d3, cos(M_PI/4));
        double d4 = avalia_cosseno(i, M_PI/3);
        printf("Taylor = %lf; Cos = %lf\t", d4, cos(M_PI/3));
        printf("\n");
    }

    return 0;
    
}
