#include "../include/binary_heap.h"

bool compareMax(const int x, const int y){
  return x>y;
}

bool compareMin(const int x, const int y){
  return x<y;
}

void copyArray(int* const out, const int* const in, const size_t in_size){
  for (size_t i = 0; i < in_size; i++){
    out[i] = in[i];
  }
}

void printArray(const int* const A, const size_t asize){
  for (size_t i = 0; i < asize; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}

int* initArray(const size_t asize){
  int* A = malloc(sizeof(int)*asize);
  for (size_t i = 0; i < asize; i++){
    A[i] = rand()%50;
  }
  return A;
}

void swap(int* i, int* j){
  int tmp = *i;
  *i = *j;
  *j = tmp;
}

int getRoot(){
  return 0;
}

size_t left( const size_t i){
  return 2*(i+1)-1;
}

size_t right( const size_t i){
  return 2*(i+1);
}

size_t parent(const size_t i){
  return (i-1)/2;
}

bool isRoot(const size_t i){
  //return !(compareMax(i,0) && compareMin(i,0));
  return i==0;
}

bool isValidNode(const BINARY_HEAP* const H, size_t const i){
  return compareMax(H->size, i);
}

int heapMin(const BINARY_HEAP* const H){
  return H->array[0];
}

/* void heapify(BINARY_HEAP* const H, size_t i) {
  
  size_t m=i, leftChild, rightChild;
  
  while(compareMin(m, H->size)) {
    m = i;

    leftChild = left(i);
    rightChild = right(i);

    if (isValidNode(H,leftChild) && H->compare(H->array[leftChild], H->array[m])) {
      m = leftChild;
    }

    if (isValidNode(H,rightChild) && H->compare(H->array[rightChild], H->array[m])) {
      m = rightChild;
    }

    if(m != i) {
      swap(&(H->array[i]), &(H->array[m]));
      i=m;
    } else return;
  }
}*/

void heapify(BINARY_HEAP* h, int i){
    int m = i;
    int lc, rc;
    int old = m;
    int finished = 0;

    while(!finished)
    {
        rc = right(m);
        lc = left(m);
        m = (isValidNode(h, lc) && h->compare(h->array[lc],h->array[m])) ? lc : m;
	      if(isValidNode(h, rc) && h->compare(h->array[rc],h->array[m])) m = rc;
        
        if(old!=m)
        {
            swap(&(h->array[m]), &(h->array[old]));
            old = m;
        }
        else 
            finished = 1;
    }
}

size_t removeMinimum(BINARY_HEAP* const H){
  H->array[0] = H->array[(H->size)-1];
  --(H->size);
  heapify(H,0);
  return H->size;
}

BINARY_HEAP* buildHeap(int* const A, size_t asize, bool (*compare)(int, int)){
  BINARY_HEAP* newHeap = (BINARY_HEAP*) malloc(sizeof(BINARY_HEAP));
  newHeap-> size = asize;
  newHeap-> array=A;
  newHeap->compare = compare;
  
  size_t parentidx = parent(asize-1); 
  for (int i = parentidx; i >= 0; i--)
    heapify(newHeap, i);

  return newHeap;
}

void heapDecreaseKey(BINARY_HEAP* const H, size_t i, const int value){
  if(compareMin(H->array[i], value)) return;
  
  H->array[i] = value;

  while(!isRoot(i) && H->compare( H->array[i], H->array[parent(i)])){
    swap(&(H->array[i]), &(H->array[parent(i)]));
    i = parent(i);
  }
}

void heapInsert(BINARY_HEAP* const H, const int value){
  ++(H->size);
  int* newArray = (int*) malloc(sizeof(int)*(H->size));
  copyArray(newArray, H->array, (H->size)-1);
  free(H->array);
  H->array=newArray;
  H->array[(H->size)-1] = INT_MAX;
  heapDecreaseKey(H, (H->size)-1, value);
}

void heapSort(int* a, int n, bool (*compare)(int, int)){

  BINARY_HEAP* b = buildHeap(a, n, compare);

  for (int i=n-1; i>=0; i--){

    swap(&(b->array[0]), &(b->array[i]));

    b->size -=1;
    heapify(b, 0);

  }
}

