#define INTEGRATION_C

#include "integration.h"

bool setQuadFormula(QuadFormula* qf, char* name)
{
  if (strcmp(name,"left"))
  {
      qf->name = name;
      qf->n = 0;
      qf->wk[0] = 1;
      qf->xk[0] = 0;
      return true;
  }
  else if (strcmp(name,"right"))
  {
      qf->name = name;
      qf->n = 0;
      qf->wk[0] = 1;
      qf->xk[0] = 1;
      return true;
  }
  if (strcmp(name,"middle"))
  {
      qf->name = name;
      qf->n = 0;
      qf->wk[0] = 1;
      qf->xk[0] = 1/2;
      return true;
  }
  if (strcmp(name,"trapezes"))
  {
      qf->name = name;
      qf->n = 1;
      qf->wk[0] = 1/2;
      qf->wk[1] = 1/2; 
      qf->xk[0] = 0;
      qf->xk[1] = 1;
      return true;
  }
  if (strcmp(name,"simpson"))
  {
      qf->name = name;
      qf->n = 3;
      qf->wk[0] = 1/6;
      qf->wk[1] = 2/3;
      qf->wk[2] = 1/6;
      qf->xk[0] = 0;
      qf->xk[1] = 
      return true;
  }
  if (strcmp(name,"gauss2"))
  {
      qf->name = name;
      qf->n = 2;
      qf->wk[0] = 1/6;
      qf->wk[1] = 2/3;
      qf->xk[0] = 0;
      qf->xk[1] = 
      return true;
  }if (strcmp(name,"gauss3"))
  {
      qf->name = name;
      qf->n = 3;
      qf->wk[0] = 1/6;
      qf->wk[1] = 2/3;
      qf->wk[2] = 1/6;
      qf->xk[0] = 0;
      qf->xk[1] = 
      qf->xk[2]
      return true;
  }
    else 
    {   
      return false;
    }
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
  printf("Quadratic formula: %s\n", qf->name);
  /* Print everything else that may be useful */
}


/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{
  double inte = 0;

  for (int i = 0; i < N; i++) {
      int ai = a + i * b - a / N;
      int bi = a + (i + 1) * b - a / N;
      int res = 0;
      int len = b - a / N;
      for (int k = 0; k < qf->n; k++) {
        res += qf->wk[k] * f( ai + qf->xk[k] * (bi - ai));

      }
      res *= bi - ai;

    inte += res;

  }
  return inte;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  return 0.0;
}


