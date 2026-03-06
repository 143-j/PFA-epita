/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "pfa.h"

/* Code here anything you want to test your pfa functions and to show your numerical results */
int main()
{
  Option option;

  option.type = CALL; /* Call or put option */
  option.S0 = 100; /* Price of the underlying asset at time 0 */
  option.K = 100; /* Strike of the option (prix d'exercice) */
  option.T = 2; /* Expiry */

    
  option.mu = 0.05;
  option.sig = 0.02;

  double res = optionPrice(&option);
  printf("optionprice : %ld", res);

  return 0;

  
}
