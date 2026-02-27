/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include <math.h>
#include "integration.h"
double f(double t)
{
  return sin(ln(t));
}

double g(double t)
{
  return cos(t*t);
}

double h(double t)
{
  return t*t + t + 1;
}


int main() {
  QuadFormula qf;
  double I1, I2, I3,I4,I5,I6,I7;
  setQuadFormula(&qf, "left");
  I1 = integrate(f, -1, 4, 5, &qf);
  printf("I1 = %f\n", I1);
  setQuadFormula(&qf, "right");
  I2 = integrate(f, -1, 4, 2, &qf);
  printf("I2 = %f\n", I2);
  setQuadFormula(&qf, "middle");
  I3 = integrate(f, -1, 4, 2, &qf);
  printf("I3 = %f\n", I3);
  setQuadFormula(&qf, "trapezes");
  I4 = integrate(f, -1, 4, 2, &qf);
  printf("I4 = %f\n", I4);
  setQuadFormula(&qf, "simpson");
  I5 = integrate(f, -1, 4, 2, &qf);
  printf("I5 = %f\n", I5);
  setQuadFormula(&qf, "gauss2");
  I6 = integrate(f, -1, 4, 2, &qf);
  printf("I6 = %f\n", I6);
  setQuadFormula(&qf, "gauss3");
  I7 = integrate(f, -1, 4, 2, &qf);
  printf("I7 = %f\n", I7);
  return 0;
}




