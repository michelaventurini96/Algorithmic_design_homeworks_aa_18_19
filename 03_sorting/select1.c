#include <stdio.h>
#include <stdlib.h>
#define N (sizeof(A)/sizeof(A[0]))

void copy(int* ar1 , const int* ar2, const int start, const int n){
	for (size_t i = start; i < start+n; i++) {
		ar1[i-start]=ar2[i];
	}
}

void SWAP(int* const A, const size_t i, const size_t p){
  //printf("inside swap\n");
    int temp = A[i];
    A[i] = A[p];
    A[p] = temp;
}

void insertionSort(int a[], const size_t n){
		if (n ==1)return;
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

void printArray(int* const array, const int array_size) {
	for (int i = 0; i < array_size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int selectPivot(const int a[], const int l, const int r){
  //printf("inside selectPivot\n");
  return 1+(r-l)/2;
}

int selectPivot1(int const a[], const int l, const int r, int n){
  //printf("inside selectPivot 1\n");
	if(l==r) return l;
  int chunk_size = (r-l+1)/5;
	//printf("chunk_size = %d\n", chunk_size);
	int* tmp = (int*) malloc(sizeof(int)*chunk_size);
	int median[5] = {0};
	for (size_t i = 0; i < 5; i++) {
		copy(tmp, a,i*chunk_size ,chunk_size);
		//printf("Print array after copy\n");
		//printArray(tmp, chunk_size);
		insertionSort(tmp, chunk_size);
		//printf("Print array after insertionSort\n");
		//printArray(tmp, chunk_size);
		median[i] = tmp[(chunk_size/2)];
		free(tmp);
		//printf("Median[%ld]=%d\n",i, median[i] );
	}
	int res;
	for (size_t i = 0; i < n; i++) {
		if (a[i] == median[3]) res = i;
	}
	return res;
}


int partition1(int a[], int left, int right, int pivotIndex){
	// Pick pivotIndex as pivot from the array
	int pivot = a[pivotIndex];

	// Move pivot to end
	SWAP(a, pivotIndex, right);

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = left;

	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot.
	for (int i = left; i < right; i++)
		if (a[i] <= pivot) SWAP(a, i, pIndex++);

	// Move pivot to its final place
	SWAP(a, pIndex, right);

	// return pIndex (index of pivot element)
	return pIndex;
}

int partition2(int A[], int left, int right, int p){
	SWAP(A, left, p); //swap the first element with the partition element
  p = left++; //the partition index becomes the index of the first element
  while (left <= right) {
    if (A[left]>A[p]) {
      SWAP(A,left,right--);
    }
    else left++;
  }
  SWAP(A,p,left);
  return p;
}

int quickselect(int A[], int left, int right, int k, int n){
	// If the array contains only one element, return that element
	if (left == right) return A[left];

	// select a pivotIndex between left and right
	int pivotIndex = selectPivot1(A, left, right, n);
	printf("Pivot index = %d\n", pivotIndex );
	pivotIndex = partition2(A, left, right, pivotIndex);

	// The pivot is in its final sorted position
	if (k == pivotIndex) return A[k];

	// if k is less than the pivot index
	else if (k < pivotIndex) return quickselect(A, left, pivotIndex - 1, k, n);

	// if k is more than the pivot index
	else return quickselect(A, pivotIndex + 1, right, k, n);
}

int main(int argc, char* argv[]){
	int A[] = { 7, 4, 6, 3, 9, 1, 2, 5, 8, 0 };
	printArray(A, N);
	int k;
	if (argc >= 2){
		if((atoi(argv[1])-1) >= N || (atoi(argv[1])-1)<0) k = 3;
		else k = atoi(argv[1])-1;
	}
	else k = 3;

	printf("%d'th smallest element is %d\n", k+1, quickselect(A, 0, N - 1, k, N));

	return 0;
}
