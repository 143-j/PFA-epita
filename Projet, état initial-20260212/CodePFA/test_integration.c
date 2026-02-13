/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include <math.h>
#include "integration.h"
double f(double t)
{
  return sin(t*t);
}
int main() {
  QuadFormula qf;
  double I1, I2, I3;
  setQuadFormula(&qf, "trapezes");
  I1 = integrate(f, -1, 4, 10, &qf);
  printf("I1 = %f\n", I1);
  setQuadFormula(&qf, "middle");
  I2 = integrate(f, -1, 4, 10, &qf);
  printf("I2 = %f\n", I2);
}




