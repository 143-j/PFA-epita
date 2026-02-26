#define INTEGRATION_C

#include "integration.h"

bool setQuadFormula(QuadFormula* qf, char* name)
{
  for (int i = 0; i < 20; i++)
  {
    qf->name[i] = '\0';
  }
  for (int i = 0; i < 5; i++)
  {
    qf->wk[i] = 0.0;
    qf->xk[i] = 0.0;
  }

  if (strcmp(name,"left") == 0)
  {
    for (int i =  0; name[i] != '\0';i++)
    {
      qf->name[i] = name[i];
    } 
      qf->n = 0;
      qf->wk[0] = 1;
      qf->xk[0] = 0;
      return true;
  }
  else if (strcmp(name,"right") == 0) 
  {
    for (int i =  0; name[i] != '\0';i++)
    {
      qf->name[i] = name[i];
    } 
      qf->n = 0;
      qf->wk[0] = 1.0;
      qf->xk[0] = 1.0;
      return true;
  }
  else if (strcmp(name,"middle") == 0)
  {
    for (int i =  0; name[i] != '\0';i++)
    {
      qf->name[i] = name[i];
    } 
      qf->n = 0;
      qf->wk[0] = 1.0;
      qf->xk[0] = 0.5;
      return true;
  }
  else if (strcmp(name,"trapezes") == 0)
  {
      for (int i =  0; name[i] != '\0';i++)
    {
      qf->name[i] = name[i];
    }
      qf->n = 1;
      qf->wk[0] = 0.5;
      qf->wk[1] = 0.5; 
      qf->xk[0] = 0.0;
      qf->xk[1] = 1.0;
      return true;
  }
  else if (strcmp(name,"simpson") == 0)
  {
      for (int i =  0; name[i] != '\0';i++)
    {
      qf->name[i] = name[i];
    } 
      qf->n = 3;
      qf->wk[0] = 1.0/6.0;
      qf->wk[1] = 2.0/3.0;
      qf->wk[2] = 1.0/6.0;
      qf->xk[0] = 0.0;
      qf->xk[1] = 1.0/2.0;
      qf->xk[2] = 1.0; 
      return true;
  }
  else if (strcmp(name,"gauss2") ==0)
  {
      for (int i =  0; name[i] != '\0';i++)
    {
      qf->name[i] = name[i];
    } 
      qf->n = 2;
      qf->wk[0] = 0.5;
      qf->wk[1] = 0.5;
      qf->xk[0] = 0.5 - 1.0/(2.0*sqrt(3.0));
      qf->xk[1] = 0.5 + 1.0/(2.0*sqrt(3.0)); 
      return true;
  }
  else if (strcmp(name,"gauss3") == 0)
  {
      for (int i =  0; name[i] != '\0';i++)
    {
      qf->name[i] = name[i];
    } 
      qf->n = 3;
      qf->wk[0] = 5.0/18.0;
      qf->wk[1] = 4.0/9.0;
      qf->wk[2] = 5.0/18.0;
      qf->xk[0] = 0.5 * (1-sqrt(0.6));
      qf->xk[1] = 0.5;
      qf->xk[2] = 0.5 * (1+sqrt(0.6));
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
  printf("Name = %s\n", qf->name);
  double inte = 0.0;
  double len = (b - a) / N;
  for (int i = 0; i < N; i++) {
      double ai = a + i * len;
      double bi = a + (i + 1) * len;
      double res = 0.0;
      for (int k = 0; k <= qf->n; k++) {
        res = res + qf->wk[k] * f( ai + qf->xk[k] * (bi - ai));}
      res = res * (bi - ai);
      inte = inte + res;
  }
  return inte;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  int N = (int) round (abs(b-a/dx));
  if (N == 0)
  {
    N = 1;
  }  
  return integrate(f,a,b,N,qf);
}


