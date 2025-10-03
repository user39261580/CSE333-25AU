// Copyright 2025 Tsung-Wei Chin
// Name: Miles TsungWei Chin
// Email: twchin@uw.edu
// Goal: C warm-up exercise

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
double nilakantha(int n);
int is_input_valid(int argc, char const *argv[]);

int main(int argc, char const *argv[]) {
  if (!is_input_valid(argc, argv)) {
    return EXIT_FAILURE;
  }

  int n = strtol(argv[1], NULL, 10);
  double pi_estimate = 0.0;
  for (int i = 0; i <= n; i++) {
    pi_estimate += nilakantha(i);
  }
  printf("Our estimate of Pi is %.20f\n", pi_estimate);
  return EXIT_SUCCESS;
}


double nilakantha(int n) {
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

int is_input_valid(int argc, char const *argv[]) {
  // Check whether args count is correct
  if (argc != 2) {
    printf("Invalid input\n");
    return 0;
  }

  // Check whether the input is a non-negative integer
  char *endptr;
  int val = strtol(argv[1], &endptr, 10);
  if (*endptr != '\0' || val < 0) {
    printf("Invalid input\n");
    return 0;
  }

  return 1;
}
