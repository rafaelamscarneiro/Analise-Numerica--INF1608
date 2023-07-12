#include <stdio.h>
#include <stdlib.h>
#include "taylor.h"

double fac(int n){
	if(n==1 || n==0){
		return 1;
	}
	else{
		return n*fac(n-1);
	}
}

double pot(double n, int m){
    double res=1;
	while(m>0){
		res *= n;
		m--;
	}
	
	return res;
}


double avalia_taylor (int n, double *c, double x0, double x){
	int i;
	double p=0;
	for(i=0; i<n; i++) {
		p += c[i]/fac(i)*pot(x-x0, i);
	}
	return p;

}

double avalia_cosseno (int n, double x){
    double *c = (double*) malloc(n*sizeof(double));
    c[0] = 1;
    
    int i, sinal = 1;
    for(i=1; i<n; i++) {
        
        c[i] = !c[i-1] * sinal;
        if(i%2) {
            sinal = -sinal;
        }
        //printf("%lf\n", c[i]);
    }
    
    double res = avalia_taylor(n, c, 0, x);
    free(c);
    return res;
} 