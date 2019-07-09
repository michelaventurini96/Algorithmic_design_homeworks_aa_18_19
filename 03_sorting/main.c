#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#include "include/binary_heap.h"
#include "include/insertion.h"
#include "include/bucket.h"
#include "include/radix.h"
#include "include/count.h"
#include "include/select.h"
#define BILLION 10E9

void revOrder(int* const a, const size_t n){
    int j;
    int key;
    for (size_t i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    //printArray(a, n);
  
}

/*Driver program to test sorting algorithms*/
int main(){

  // variables for timig
  struct timespec requestStart, requestEnd;
  double accum;

  //printf("Size\t\tIns. Sort W\tIns. Sort B\tQuick Sort W\tQuick Sort B\tBucket Sort\tRadix Sort\tCounting Sort\tHeap Sort\tSelect Algo.\n");

  for(size_t N=8 ; N < 10e3 ; N *= 2) {

    printf("%ld\t", N); // size of array to sort

    // array for insertion sort, quick sort, heap sort and select
    int* A = (int*) malloc(N*sizeof(int));
    initArray_int(A, N);
    // printArray_int(A,N);

    // array for counting sort
    char* C = (char*) malloc(N*sizeof(char));
    initArray_char(C, N);
    // printArray_char(C, N);

    //Array for bucketSort 
    float* B = (float*) malloc(N*sizeof(float));
    initArray_float(B, N);
    // printArray_float(B,N);
    
  // timing
    // // insertion sort avg
    // clock_gettime(CLOCK_REALTIME, &requestStart);
    // insertionSort(A, N);
    // clock_gettime(CLOCK_REALTIME, &requestEnd);
    // accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    // printf("\t%lf", accum);
    // // printArray_int(A,N);

    // // insertion sort best case
    // clock_gettime(CLOCK_REALTIME, &requestStart);
    // insertionSort(A, N);
    // clock_gettime(CLOCK_REALTIME, &requestEnd);
    // accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    // printf("\t%lf", accum);
    // // printArray_int(A,N);

    // // insertion sort worst case (reverse sorting)
    // initArray_int(A, N);
    // revOrder(A,N);
    // clock_gettime(CLOCK_REALTIME, &requestStart);
    // insertionSort(A, N);
    // clock_gettime(CLOCK_REALTIME, &requestEnd);
    // accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    // printf("\t%lf\n", accum);
    // // printArray_int(A,N);
    
    // // quick sort avg
    // initArray_int(A, N);
    // clock_gettime(CLOCK_REALTIME, &requestStart);
    // quickSort(A, 0, N-1);
    // clock_gettime(CLOCK_REALTIME, &requestEnd);
    // accum = (requestEnd.tv_sec - requestStart.tv_sec) + (requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    // printf("\t%lf", accum);
    // // printArray_int(A,N);

    // // quicksort best case
    // initArray_int(A, N);
    // insertionSort(A, N);
    // clock_gettime(CLOCK_REALTIME, &requestStart);
    // quickSortBest(A, 0, N-1);
    // clock_gettime(CLOCK_REALTIME, &requestEnd);
    // accum = (requestEnd.tv_sec - requestStart.tv_sec) + (requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    // printf("\t%lf", accum);
    // // printArray_int(A,N);

    //     // quicksort worst case
    // initArray_int(A, N);
    // revOrder(A, N);
    // clock_gettime(CLOCK_REALTIME, &requestStart);
    // quickSort(A, 0, N-1);
    // clock_gettime(CLOCK_REALTIME, &requestEnd);
    // accum = (requestEnd.tv_sec - requestStart.tv_sec) + (requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    // printf("\t%lf\n", accum);
    // // printArray_int(A,N);

    // bucketsort
    clock_gettime(CLOCK_REALTIME, &requestStart);
    bucketSort(B, N);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    printf("\t%lf", accum);
    // printArray_float(B,N);
    
    // radix sort
    initArray_r(A, N);
    clock_gettime(CLOCK_REALTIME, &requestStart);
    radixsort(A, N);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    printf("\t%lf", accum);
    // printArray_int(A,N);

    // counting sort
    clock_gettime(CLOCK_REALTIME, &requestStart);
    countSort(C, N);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    printf("\t%lf\n", accum);
    // printArray_char(C, N);

    // heap sort
    // initArray_int(A, N);
    // clock_gettime(CLOCK_REALTIME, &requestStart);
    // heapSort(A, N, compareMax);
    // clock_gettime(CLOCK_REALTIME, &requestEnd);
    // accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    // printf("\t%lf", accum);
    // // printArray_int(A, N);

    // // select
    // int i = rand()%(N-2); // index
    // initArray_int(A, N);
    // clock_gettime(CLOCK_REALTIME, &requestStart);
    // //printArray_int(A, N);
    // ksmallest(A, N, i);
    // clock_gettime(CLOCK_REALTIME, &requestEnd);
    // accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    // printf("\t%lf\n", accum);

    // //deallocate memory
     free(A);
    // free(B);
    // free(C);
  }
    return 0;
}
