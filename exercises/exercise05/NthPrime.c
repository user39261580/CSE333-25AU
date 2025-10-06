// Copyright 2025 Tsung-Wei Chin
// Name: Miles TsungWei Chin
// Email: twchin@uw.edu

#include "NthPrime.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int64_t Eratosthenes(int16_t n);
static int32_t EstimateUpperBound(int16_t n);

// Returns the n-th prime number.
int64_t NthPrime(int16_t n) {
  // Handle invalid input
  if (n < 1) {
    return -1;
  }

  return Eratosthenes(n);
}

// Implementation of the Sieve of Eratosthenes algorithm
static int64_t Eratosthenes(int16_t n) {
  int32_t upper_bound = EstimateUpperBound(n);

  // Allocate memory for the sieve
  bool* is_prime = (bool*) malloc((upper_bound + 1) * sizeof(bool));
  if (is_prime == NULL) {
    return EXIT_FAILURE;
  }

  // Initialize the sieve
  for (int32_t i = 0; i <= upper_bound; i++) {
    is_prime[i] = true;
  }
  is_prime[0] = false;
  is_prime[1] = false;

  // Sieve of Eratosthenes
  for (int32_t p = 2; p * p <= upper_bound; p++) {
    if (is_prime[p]) {
      for (int32_t multiple = p * p; multiple <= upper_bound; multiple += p) {
        is_prime[multiple] = false;
      }
    }
  }

  // Find the n-th prime number
  int16_t count = 0;
  for (int32_t i = 2; i <= upper_bound; i++) {
    if (is_prime[i]) {
      count++;
      if (count == n) {
        free(is_prime);
        return i;
      }
    }
  }

  free(is_prime);
  return -1;
}

// Estimate n-th prime number upper bound based on Dusart's inequality
static int32_t EstimateUpperBound(int16_t n) {
  // Handle invalid input
  if (n < 1) {
    return -1;
  }

  // Handle small n values
  if (n < 6) {
    return 15;
  }

  // Dusart's inequality for n >= 6
  double log_n = log((double)n);
  double log_log_n = log(log_n);
  double upper_bound = n * (log_n + log_log_n);
  return (int32_t) upper_bound;
}
