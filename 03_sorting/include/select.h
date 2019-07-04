#ifndef __SELECT__
#define __SELECT__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

void swap_a(int* i, int* j);
void copy(int* ar1 , const int* ar2, const int start, const int n);
int selectPivot(int* const a, const int l, const int r);
int partition1(int* a, int low, int high);
int partition_s(int* A, int left, int right);
int quickselect(int* A, int left, int right, int k, const int n);
int ksmallest(int* A, int n, int k);

#endif