/*
 * File:     pi_seq.c
 *
 * Purpose:  Estimate pi using a monte carlo method
 *
 * Compile:  gcc -Wall -o pi_seq pi_seq.c
 *
 * Input:    Number of "dart tosses"
 * Output:   Estimate of pi.
 *
 * IPP:      Programming Assignment 3.2
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"

double monte_carlo(long long number_of_tosses);

/*-------------------------------------------------------------------*/
int main(int argc, char *argv[]) {
  long long int number_of_tosses;

  double pi_estimate;
  double PI25DT = 3.141592653589793238462643;

  if (argc != 2) {
    printf("Missing argument. Usage: ./pi <#tosses>\n");
    return 1;
  }

  number_of_tosses = atoll(argv[1]);
  if (number_of_tosses <= 0) {
    printf("Non-positive input. Usage: ./pi <#tosses>\n");
    return 1;
  }

  double startwtime = get_time();
  pi_estimate = monte_carlo(number_of_tosses);
  double endwtime = get_time();
  printf("Program pi_seq.c: wall clock time = %f seconds\n",
         endwtime - startwtime);
  printf("pi estimate = %f\n", pi_estimate);
  printf("Error = %f\n", fabs(pi_estimate - PI25DT));
  return 0;
}

/*-------------------------------------------------------------------*/
double monte_carlo(long long number_of_tosses) {
  long long int i;
  double x, y, pi_estimate;
  double distance_squared;
  long long int number_in_circle = 0;

  for (i = 0; i < number_of_tosses; i++) {
    x = 2 * random() / ((double)RAND_MAX) - 1.0;
    y = 2 * random() / ((double)RAND_MAX) - 1.0;
    distance_squared = x * x + y * y;
    if (distance_squared <= 1) {
      number_in_circle++;
    }
  }

  pi_estimate = 4 * number_in_circle / ((double)number_of_tosses);
  return pi_estimate;
}
