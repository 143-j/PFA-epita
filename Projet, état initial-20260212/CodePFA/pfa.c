

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
  return 0.5 * (integrate_dx(phi,0,x,pfa_dt,pfaQF));
}

/* =====================================
   Finance function: price of an option 
*/
double optionPrice(Option* option)
{
  if (option != NULL)
  {
    double sig = option->sig;
    double T = option->T;
    double mu = option->mu;
    double S0 = option->S0;
    double K = option->K;
    double z0 = log(K/S0) - (mu - sig * sig/2) * T;
    if (option-> type == CALL)
    {
      return S0 * exp(mu*T) * PHI(sig * sqrt(T) - z0) - K* PHI(-z0);
    }
    else if (option-> type == PUT)
    {
      return K * PHI(z0) - S0 * exp(mu*T) * PHI(z0 - sig * sqrt(T));
    }
  }
  else 
  {
    return -1.0;
  }
}



/* ===============================================*/
/* Insurance functions */

/* Probability density function (PDF) of variable X.
   X is the reimbursement in case of a claim from the client.
*/
double clientPDF_X(InsuredClient* client, double x)
{
  return (1 / client->s * x) * phi((log(x) - client-> m) / client->s)
}


/* Cumulative distribution function (CDF) of variable X.
   X is the reimbursement in case of a claim from the client.
*/
double clientCDF_X(InsuredClient* client, double x)
{
  return PHI((log(x) - client -> m) / client -> s);
}


/* Probability density function (PDF) of variable X1+X2.
   X1 and X2 are the reimbursements of the two claims from the client (assuming there are 
   two claims).
*/
double clientPDF_X1X2(InsuredClient* client, double x)
{
  return integrate_dx(clientPDF_X() *  ,0,x,pfa_dt,&pfaQF)
}


/* Cumulative distribution function (CDF) of variable X1+X2.
   X1 and X2 are the reimbursements of the two claims from the client (assuming there are 
   two claims).
*/
double clientCDF_X1X2(InsuredClient* client, double x)
{
  return integrate_dx();
}



/* Cumulative distribution function (CDF) of variable S.
   Variable S is the sum of the reimbursements that the insurance company will pay to client.
*/
double clientCDF_S(InsuredClient* client, double x)
{
  return 0.0;
}




