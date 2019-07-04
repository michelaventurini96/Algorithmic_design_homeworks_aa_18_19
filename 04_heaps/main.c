#include<stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include "include/binary_heap.h"

int main() {
  
  size_t asize = 8;
  int* A = initArray(asize); //printArray(A, asize);

  BINARY_HEAP* H = buildHeap(A, asize, compareMax);
  printf("Starting Heap\n");
  printArray(H->array, H->size);
  
  heapInsert(H, 3);
  printf("Heap with new value\n");
  printArray(H->array, H->size);

  asize = removeMinimum(H);
  printf("Heap without minimum/maximum\n");
  printArray(H->array, asize);

  // printf("HeapSort\n");
  // int* B= initArray(asize);
  // printArray(B, asize);
  // heapSort(B, asize, compareMax);
  // printArray(B, asize);

  free(H);
  //free(B);

  return 0;

}
