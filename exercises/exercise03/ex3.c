// Copyright 2025 Tsung-Wei Chin
// Name: Miles TsungWei Chin
// Email: twchin@uw.edu
// Goals: Write a program that uses structs, typedef, and dynamic memory allocation (malloc/free).

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct Point3d_st{
  uint16_t x;
  uint16_t y;
  uint16_t z;
} Point3d;

Point3d* AllocatePoint3d(uint16_t x, uint16_t y, uint16_t z);

int main(int argc, char const *argv[])
{
  uint16_t x = 1;
  uint16_t y = 2;
  uint16_t z = 3;

  Point3d* point = AllocatePoint3d(x, y, z);

  if (point == NULL) {
    printf("Memory allocation failed\n");
    return EXIT_FAILURE;
  }

  if (point->x != x) {
    printf("Point3d.x value is incorrect\n");
    return EXIT_FAILURE;
  }

  if (point->y != y) {
    printf("Point3d.y value is incorrect\n");
    return EXIT_FAILURE;
  }

  if (point->z != z) {
    printf("Point3d.z value is incorrect\n");
    return EXIT_FAILURE;
  }

  free(point);
  return EXIT_SUCCESS;
}

Point3d* AllocatePoint3d(uint16_t x, uint16_t y, uint16_t z) {
  Point3d* point = (Point3d*) malloc(sizeof(Point3d));

  point->x = x;
  point->y = y;
  point->z = z;
  return point;
}