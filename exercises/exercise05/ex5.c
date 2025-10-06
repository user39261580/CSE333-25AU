// Copyright 2025 Tsung-Wei Chin
// Name: Miles TsungWei Chin
// Email: twchin@uw.edu

#include "NthPrime.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int main(void) {
  /* Test NthPrime with two non-trivial inputs and print input/output. */
  int16_t tests[] = {1, 2, 3, 10, 100, 1000};
  size_t num_tests = sizeof(tests) / sizeof(tests[0]);

  for (size_t i = 0; i < num_tests; i++) {
    int16_t n = tests[i];
    int64_t prime = NthPrime(n);
    printf("NthPrime(%d) = %" PRId64 "\n", (int)n, prime);
  }

  return EXIT_SUCCESS;
}
