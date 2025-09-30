// Copyright 2025 Tsung-Wei Chin
// Name: Miles TsungWei Chin
// Email: twchin@uw.edu
// Subject: Insertion sort for an array of integers

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h> 

void PrintBytes(void* mem_addr, int num_bytes);

int main(int argc, char **argv) {
  char     char_val = '0';
  int32_t  int_val = 1;
  float    float_val = 1.0;
  double   double_val  = 1.0;

  typedef struct {
    char     char_val;
    int32_t  int_val;
    float    float_val;
    double   double_val;
  } Ex2Struct;

  Ex2Struct struct_val = { '0', 1, 1.0, 1.0 };

  PrintBytes(&char_val, sizeof(char));
  PrintBytes(&int_val, sizeof(int32_t));
  PrintBytes(&float_val, sizeof(float));
  PrintBytes(&double_val, sizeof(double));
  PrintBytes(&struct_val, sizeof(struct_val));

  return EXIT_SUCCESS;
}

void PrintBytes(void* mem_addr, int num_bytes) {
  printf("The %d bytes starting at %p are: ", num_bytes, mem_addr);
  uint8_t* byte_ptr = (uint8_t*) mem_addr;
  for (int i = 0; i < num_bytes; i++, byte_ptr++) {
    printf("%02" PRIx8 " ", *byte_ptr);
  }
  printf("\n");
}