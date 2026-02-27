

// #define GRAPHIC

#define PFA_C

#include "pfa.h"

/* Initialize the integration variables.
   Arguments :
   - quadrature : name of the quadrature formula that will be used. It can be "left", "right", 
     "middle", "trapezes", "simpson", "gauss2" or "gauss3".
   - dt : a positive value, which will be used to decide the number of subdivisions of an 
          interval [a,b], when computing the integration.
          The number of subdivisions will be N such that (b-a)/N ~ dt
*/
bool init_integration(char* quadrature, double dt)
{
  
  
  if (dt < 0) {
    return false;
  }

  if (setQuadFormula(&pfaQF, quadrature)) {
    
    pfa_dt = dt;

    return true;
  }

  else 
  {   
    return false;
  }
}



/* Density of the normal distribution */
double phi(double x)
{
  return 0.398942280401433 * exp( -x*x/2 );
}

/* Cumulative distribution function of the normal distribution */
double PHI(double x)
{
  double f = phi(x);
  return 1.0/2.0 + integrate(&f, 0, x, pfa_dt, &pfaQF);
}

/* =====================================
   Finance function: price of an option 
*/
double optionPrice(Option* option)
{
  double z0 = (log(option->K/option->S0) - ((option->mu - (option->sig * option->sig)/2.0)) * option->T) / (option->sig * sqrt(option->T) );
  
  if (option->type == CALL) {
    double C = option->S0 * exp(option->mu * option->T) * PHI(option->sig * sqrt(option->T) - z0) - option->K * PHI(-z0);
    return C;
  }
  if (option->type == PUT) {
    double P = option->K * PHI(z0) - option->S0 * exp(option->mu * option->T) * PHI(z0 - option->sig * sqrt(option->T));
    return P;
  }
  else {
    return 0.0;
  }
}



/* ===============================================*/
/* Insurance functions */

/* Probability density function (PDF) of variable X.
   X is the reimbursement in case of a claim from the client.
*/
double clientPDF_X(InsuredClient* client, double x)
{
  return 0.0;
}


/* Cumulative distribution function (CDF) of variable X.
   X is the reimbursement in case of a claim from the client.
*/
double clientCDF_X(InsuredClient* client, double x)
{
  return 0.0;
}


/* Probability density function (PDF) of variable X1+X2.
   X1 and X2 are the reimbursements of the two claims from the client (assuming there are 
   two claims).
*/
double clientPDF_X1X2(InsuredClient* client, double x)
{
  return 0.0;
}


/* Cumulative distribution function (CDF) of variable X1+X2.
   X1 and X2 are the reimbursements of the two claims from the client (assuming there are 
   two claims).
*/
double clientCDF_X1X2(InsuredClient* client, double x)
{
  return 0.0;
}



/* Cumulative distribution function (CDF) of variable S.
   Variable S is the sum of the reimbursements that the insurance company will pay to client.
*/
double clientCDF_S(InsuredClient* client, double x)
{
  return 0.0;
}




