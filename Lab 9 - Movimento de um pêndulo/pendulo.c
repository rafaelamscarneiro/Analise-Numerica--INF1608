#include "pendulo.h"
#include <math.h>
#include <stdio.h>

double pendulo(double t, double h, double *theta, double *w) {
  double k1_theta, k2_theta, k3_theta, k4_theta;
  double k1_w, k2_w, k3_w, k4_w;
  double g = 9.8, l = 10;

  k1_theta = h * (*w);
  k1_w = h * ((-g /l) * sin(*theta));
  
  k2_theta = h * ((*w) + (k1_w/2)); 
  k2_w = h * (((-g /l) * sin((*theta) + (k1_theta/2)))); 

  k3_theta = h * ((*w) + (k2_w/2));
  k3_w = h * ((-g/l) * sin((*theta) + (k2_theta/2)));

  k4_theta = h * ((*w) + k3_w);
  k4_w = h * ((-g/l) * sin((*theta) + k3_theta));

  (*theta) += (1.0/6.0) * (k1_theta + (2*k2_theta) + (2*k3_theta) + k4_theta);
  (*w) += + (1.0/6.0) * (k1_w + (2*k2_w) + (2*k3_w) + k4_w);
  return (t+h);
}

double periodo(double theta_0) {
  double t1 = 0;
  double h = 1E-3;
  double omega_0 = 0;
  double omega_1 = omega_0;
  double t2 = 0;
  double periodo = 0;
  
  int cont = 0;
  while (cont < 10) {
    t1 = t2;
    omega_0 = omega_1;
    printf("1omega1 = %g\n", omega_1);
    t2 = pendulo(t1, h, &theta_0, &omega_1);
    if ((omega_0 * omega_1) < 0) {
      periodo += (t1 + (fabs(omega_0) / (fabs(omega_0) + fabs(omega_1)))*(t2-t1));
      //cont++;
    }
    printf("2omega0 = %g\n", omega_0);
    printf("2omega1 = %g\n", omega_1);
    cont++;
  }
  return periodo/10;
}

double periodo_simplificado(double theta0) { return 2 * M_PI * sqrt(9.8 / 10); }