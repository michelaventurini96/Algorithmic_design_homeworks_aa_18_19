#include<stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<stdbool.h>

bool compareMax(const int x, const int y){
  return x>y;
}

bool compareMin(const int x, const int y){
  return x<y;
}

typedef struct binary_heap{
  int* array;
  size_t size;
  bool (*compare)(int, int);
}BINARY_HEAP;


void copyArray(int* const out, const int* const in, const size_t in_size);
void printArray(const int* const A, const size_t asize);
int* initArray(const size_t asize);
void swap(int* i, int* j);
int getRoot();
size_t left( const size_t i);
size_t right( const size_t i);
size_t parent(const size_t i);
bool isRoot(const size_t i);
bool isValidNode(const BINARY_HEAP* const H, size_t const i);
int heapMin(const BINARY_HEAP* const H);
void heapify(BINARY_HEAP* h, int i);
size_t removeMinimum(BINARY_HEAP* const H);
BINARY_HEAP* buildHeap(int* const A, size_t asize, bool  (*compare)(int, int));
void heapDecreaseKey(BINARY_HEAP* const H, size_t i, const int value);
void heapInsert(BINARY_HEAP* const H, const int value);
void heapSort(int* a, int n, bool (*compare)(int, int));