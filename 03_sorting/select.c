#include<stdio.h>
#include<stdlib.h>

void insertionSort(int a[], int n)
{
    size_t j;
    int key;
    for (size_t i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void printArray(int* const array, const size_t array_size) {
	for (size_t i = 0; i < array_size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int* const A, const size_t i, const size_t p){
  //printf("inside swap\n");
    int temp = A[i];
    A[i] = A[p];
    A[p] = temp;
}

size_t partition(int* const A, size_t left, size_t right, size_t p){
  //printf("inside partition\n");
  swap(A, left, p); //swap the first element with the partition element
  p = left++; //the partition index becomes the index of the first element
  while (left <= right) {
    if (A[left]>A[p]) {
      printf("A[%ld] = %d (A[left]) > A[%ld] = %d A(part. index)\n", left, A[left], p,A[p]);
      swap(A,left,right--);
    }
    else left++;
  }
  swap(A,p,left);
  return p;
}

size_t selectPivot(int* A, size_t l, size_t r){
  //printf("inside selectPivot\n");
  return 1+(r-l)/2;
}

size_t selectAlgo(int* A, size_t idx, size_t l, size_t r){
	if(l==r) return A[l];
  //printf("inside selectAlgo\n");
  size_t pivotIndex = selectPivot(A,l,r); //select the pivot index
  printf("The pivotIndex is %ld\n", pivotIndex);

  size_t partition_idx = partition(A, l, r, pivotIndex);

  //printArray(A,11);
  //printf("partition index is %ld\n", partition_idx);
  if(idx==partition_idx) return partition_idx;

  else if(idx<partition_idx) selectAlgo(A, idx, l, partition_idx-1);

  else selectAlgo(A, idx, partition_idx+1, r); //+partition_idx;
}

int main(int argc, char const *argv[]) {
	size_t elem = atoi(argv[1]);
  int A[] = {2,7,4,8,3,9,1,5,10,0,6};//(int*) malloc(sizeof(int)*15);
  size_t array_size = sizeof(A)/sizeof(int);
	swap(A, 0, 10);
	printArray(A, array_size);
  // //printf("%ld\n", array_size);
  // size_t index = selectAlgo(A, elem, 0, array_size-1);
  // printf("index = %ld\n", index);
  // printf("The %ld-th smallest element of the array is %d\n",elem , A[index] );
  // return 0;
}
