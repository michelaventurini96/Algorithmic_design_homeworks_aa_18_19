#ifndef __RADIX__
#define __RADIX__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

void initArray_r(int* const a, const size_t n);
int getMax(int* a, size_t n);
void countSort_r(int* a, int n, int exp);
void radixsort(int* a, int n);

#endif