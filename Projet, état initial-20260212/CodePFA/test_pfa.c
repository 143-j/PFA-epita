/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "pfa.h"

/* Code here anything you want to test your pfa functions and to show your numerical results */
int main()
{
  QuadFormula pfaQF;
  init_integration("simpson", 1000);

  Option option;

  option.type = PUT; /* Call or put option */
  option.S0 = 100; /* Price of the underlying asset at time 0 */
  option.K = 115; /* Strike of the option (prix d'exercice) */
  option.T = 2; /* Expiry */
  option.mu = 0.05;
  option.sig = 0.02;

  double res = optionPrice(&option);
  printf("optionprice : %lf\n", res);

  InsuredClient client;
  client.m = 1.0;
  client.s = 1.0;
  double p[3] = {0.9, 0.05, 0.05};
  client.p = p;

  res = clientPDF_X(&client, 1.0);
  printf("clientPDF_X : %lf\n", res);

  res = clientCDF_X(&client, 1.0);
  printf("clientCDF_X : %lf\n", res);

  res = clientPDF_X1X2(&client, 1.0);
  printf("clientPDF_X1X2 : %lf\n", res);

  res = clientCDF_X1X2(&client, 1.0);
  printf("clientCDF_X1X2 : %lf\n", res);
  res = clientCDF_S(&client, 1.0);
  printf("clientCDF_S : %lf\n", res);
  return 0;
}
