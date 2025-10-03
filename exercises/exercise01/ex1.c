// Copyright 2025 Tsung-Wei Chin
// Name: Miles TsungWei Chin
// Email: twchin@uw.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#define ARRAY_SIZE 12

// Function declarations
int CopyAndSort(int64_t src_array[], int64_t dest_array[], int array_size);
int IsInputValid(int64_t src_array[], int64_t dest_array[], int array_size);
void InsertionSort(int64_t new_num, int64_t dest_array[], int array_size);

int main(int argc, char const *argv[]) {
  int64_t unsorted_array[] = {3, 2, -5, 7, 17, 42, 6, 333, 7, 8, -8, 6};
  int64_t sorted_array[ARRAY_SIZE];

  if (CopyAndSort(unsorted_array, sorted_array, ARRAY_SIZE) == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }

  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%ld ", sorted_array[i]);
  }

  return EXIT_SUCCESS;
}

int CopyAndSort(int64_t src_array[], int64_t dest_array[], int array_size) {
  if (!IsInputValid(src_array, dest_array, array_size)) {
    return EXIT_FAILURE;
  }

  // Handle empty array
  if (array_size == 0) {
    return EXIT_SUCCESS;
  }

  dest_array[0] = src_array[0];

  for (int i = 1; i < array_size; i++) {
    InsertionSort(src_array[i], dest_array, i + 1);
  }

  return EXIT_SUCCESS;
}

int IsInputValid(int64_t src_array[], int64_t dest_array[], int array_size) {
  // Checking for same input and output arrays
  if (src_array == dest_array) {
    printf("Input and output arrays must be different\n");
    return 0;
  }

  // Checking for NULL pointers
  if (src_array == NULL || dest_array == NULL) {
    printf("Invalid array pointer\n");
    return 0;
  }

  // Checking for negative array size
  if (array_size < 0) {
    printf("Invalid array size\n");
    return 0;
  }

  return 1;
}

void InsertionSort(int64_t new_num, int64_t dest_array[], int array_size) {
  int index = array_size - 1;
  while (index > 0 && dest_array[index - 1] > new_num) {
    dest_array[index] = dest_array[index - 1];
    index--;
  }
  dest_array[index] = new_num;
}
