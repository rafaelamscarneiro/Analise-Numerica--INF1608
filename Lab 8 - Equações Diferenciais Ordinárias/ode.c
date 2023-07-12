#include "ode.h"
#include <stdio.h>
#include <math.h>

double PontoMedio (double t0, double t1, double h, double y0, double (*f) (double t, double y))
{
  double passo, fmed, t, y;
  y = y0;
  t = t0;
  while(fabs(t1 - t) >= 1E-7) {
    if((t + h) > t1)
    {
      h = t1-t;
    }
    passo = h*f(t, y);
    fmed = f(t + h/2, y + passo/2);
    t += h;
    y = y + h*fmed;
  }
  return y;
}

double PontoMedioAdapt (double t0, double t1, double h0, double y0, double (*f) (double t, double y), double tol) {
  double y1, y2, gama, erro, y, h, t;
  t = t0;
  y = y0;
  h = h0;
  while(fabs(t1 - t) >= 1E-7) {
    if(t+h > t1) {
      h = t1-t;
    }
    y1 = PontoMedio(t, t+h, h, y, f);
    y2 = PontoMedio(t, t+h, h/2, y, f);
    erro = (y2-y1)/3;
    gama = pow((tol/fabs(erro)), 1/3);
    if(gama >=1) {
      if(gama > 1.2) {
        gama = 1.2;
      }
      y = y2 + erro;
      h *= gama;
      t += h;
    }
    else {
      h *= gama;
     // y1 = PontoMedio(t, t+h, h, y, f);
     // y2 = PontoMedio(t, t+h/2, h/2, y, f);
    //  y = y2 + erro;
    }
  }
  return y;
  
}