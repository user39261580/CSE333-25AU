// Copyright 2025 Tsung-Wei Chin
// Name: Miles TsungWei Chin
// Email: twchin@uw.edu
// Subject: Insertion sort for an array of integers

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>

#define SIZE 12
// Function declarations
int CopyAndSort(int64_t *input_array, int64_t *output_array, size_t array_length);
// definition placed before use to avoid implicit declaration issues
int IsInputValid(int64_t *input_array, int64_t *output_array, size_t array_length) {
  // Checking for same input and output arrays
  if (input_array == output_array) {
    printf("Input and output arrays must be different\n");
    return 0;
  }

  // Checking for NULL pointers
  if (input_array == NULL || output_array == NULL) {
  for (size_t i = 0; i < SIZE; i++) {
    printf("%" PRId64 " ", sorted_array[i]);
  }
  printf("\n");

  // (size_t can't be negative, so no negative length check needed)
  return 1;
int CopyAndSort(int64_t *input_array, int64_t *output_array, size_t array_length) {
  if (!IsInputValid(input_array, output_array, array_length)) {
    return EXIT_FAILURE;
  }

  if (array_length == 0) {
    return EXIT_SUCCESS;
  }

  // Copy input to output
  for (size_t i = 0; i < array_length; i++) {
    output_array[i] = input_array[i];
  }

  // Insertion sort (ascending)
  for (size_t i = 1; i < array_length; i++) {
    int64_t key = output_array[i];
    size_t j = i;
// (IsInputValid definition moved above) int64_t largest_value = input_array[0];

  for (size_t i = 0; i < array_length; i++) {
  }

  return EXIT_SUCCESS;
}

int IsInputValid(int64_t *input_array, int64_t *output_array, size_t array_length) {
  // Checking for same input and output arrays
  if (input_array == output_array) {
    printf("Input and output arrays must be different\n");
    return 0;
  } 

  // Checking for NULL pointers
  if (input_array == NULL || output_array == NULL) {
    printf("Invalid array pointer\n");
    return 0;
  }

  // Checking for negative array length
  if (array_length < 0) {
    printf("Invalid array length\n");
    return 0;
  }

  return 1;
}