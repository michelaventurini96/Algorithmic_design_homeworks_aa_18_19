#ifndef __INSERTION__
#define __INSERTION__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>


void initArray_int(int* a, const size_t n);
void printArray_int(const int* const a, const size_t n);
void swap_int(int* a, int* b);
int partition (int* arr, int low, int high);
void quickSort(int* arr, int low, int high);
void quickSortBest(int* arr, int low, int high);
void insertionSort(int* a, const size_t n);

#endif
