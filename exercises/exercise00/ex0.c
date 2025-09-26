// Name: Miles TsungWei Chin
// Email: twchin@uw.edu

// Recursive Pi calculator based on Nilakantha series

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declaration for recursive Nilakantha series 
double Nilakantha(int n);

int main(int argc, char const *argv[])
{
  int n = strtol(argv[1], NULL, 10);
  double pi_estimate = 0.0;
  for (int i = 0; i <= n; i++) {
    pi_estimate += Nilakantha(i);
  }
  printf("Our estimate of Pi is %.20f\n", pi_estimate);
  return EXIT_SUCCESS;
}


double Nilakantha(int n) {
  if (n == 0) {
    return 3.0;
  } else {
    double term = (4.0 / ((2.0 * n) * (2.0 * n + 1) * (2.0 * n + 2)));
    if (n % 2 == 0) {
      return 0 - term;
    } else {
      return 0 + term;
    }
  }
}