/* File:      pi_mc_test_pth.c
 * Purpose:   Estimate pi using pthreads and monte carlo method
 *
 * Compile:   gcc -O2 -Wall pi_mc_test_pth.c pi_mc_pth.c -lpthread
 *            needs timer.h,
 * Run:       ./pi_mc_test_pth <number of threads>
 * Output:    Multiple test results to estimate pi with the different numbers of
 *            tosses
 *
 * IPP:       Related to textbook programming assignment 4.2
 */

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "minunit.h"
#include "pi_mc_pth.h"

double PI25DT = 3.141592653589793238462643;

char msgbuf[100];

/*-------------------------------------------------------------------
 * Test with running work threads and passing  the  number  of tosses
 * If failed, return a message string
 * If successful, return NULL
 */
char* pi_test(char* testmsg, long long int no_tosses, double threshold) {
  double startwtime = 0, endwtime = 0;
  double error, pi_estimate;

  printf("%s: Test function parallel_pi()\n", testmsg);

  startwtime = get_time();
  pi_estimate = parallel_pi(no_tosses, thread_count);
  endwtime = get_time(); 

  printf("%s: Wall clock time = %f with %d threads\n",
    testmsg, endwtime - startwtime, thread_count);
  printf("%s: pi estimate = %f\n", testmsg, pi_estimate);

  error=fabs(pi_estimate - PI25DT);
  printf("%s: Error = %f\n", testmsg, error);

  sprintf(msgbuf, "%s: Failed due to a large error", testmsg);
  mu_assert(msgbuf,  error < threshold);

  return NULL;
}

char* pi_test1() { return pi_test("Test 1", 1000000, 0.01); }

char* pi_test2() { return pi_test("Test 2", 100000000, 0.01); }

/*-------------------------------------------------------------------
 * Run all tests.  Ignore returned messages.
 */
void run_all_tests(void) {
  //mu_run_test(pi_test1);
  mu_run_test(pi_test2);
}

/*-------------------------------------------------------------------
 * The main entrance to run all tests.
 */
int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("incorrect # of arguments");
    printf("./pi_mc_test_pth  <number of threads> \n");
    return 1;
  }
  thread_count = atoi(argv[1]);
  if (thread_count <= 0 || thread_count > THREAD_COUNT_MAX) {
    printf("The number of threads is not positive or too big\n");
    return 1;
  }
  run_all_tests();
  mu_print_test_summary("Summary:");
  return 0;
}
