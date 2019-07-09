#include<stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
#include "include/binary_heap.h"

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time){
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
};

int main() {
  struct timespec b_time, e_time;
  
  for (size_t asize = 2; asize <= 256; asize*=2)
  {

    int* A = initArray(asize); //printArray(A, asize);

    // BINARY_HEAP* H = buildHeap(A, asize, compareMax);
    // printf("Starting Heap\n");
    // printArray(H->array, H->size);
    
    // heapInsert(H, 3);
    // printf("Heap with new value\n");
    // printArray(H->array, H->size);

    // asize = removeMinimum(H);
    // printf("Heap without minimum/maximum\n");
    // printArray(H->array, asize);

    // printf("HeapSort\n");
    int* B= initArray(asize);
    // printArray(B, asize);
    clock_gettime(CLOCK_REALTIME, &b_time);
    heapSort(B, asize, compareMax);
    clock_gettime(CLOCK_REALTIME, &e_time);
    printf("size: %d, %lf\n", asize, get_execution_time(b_time, e_time));
    // printArray(B, asize);

    // free(H);
    free(B);
  }
  return 0;

}
