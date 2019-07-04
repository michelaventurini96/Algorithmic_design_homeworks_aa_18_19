#include "../include/select.h"
#include "../include/insertion.h"

void swap_a(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void copy(int* ar1 , const int* ar2, const int start, const int n){
	for (int i = start; i < start+n; i++) ar1[i-start]=ar2[i];
}

/*void insertionSort(int* a, int n){
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}*/

int selectPivot(int* const a, const int l, const int r){
	//if(l==r) return l;
	//printArray(a,n);
  int chunk_size = (r-l+1)/5, res, median[5] = {0};
	int* tmp;
	if(chunk_size < 1)
		return l;

  else
	 tmp = (int*) malloc(sizeof(int)*chunk_size);

	for (size_t i = 0; i < 5; i++) {//sort each chunk
		copy(tmp, a,i*chunk_size+l ,chunk_size);
		insertionSort(tmp, chunk_size);
		median[i] = tmp[(chunk_size/2)];
	}

	for (int i = l; i < r+1; i++) if(a[i] == median[3]) res = i; //find index of the median

  free(tmp);
	return res;
}

int partition1(int* a, int low, int high){
    int pivot = selectPivot(a, low, high);//a[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (a[j] <= pivot) {

            i++; // increment index of smaller element
            swap_a(&a[i], &a[j]);
        }
    }
    swap_a(&a[i + 1], &a[high]);
    return (i + 1);
}

int partition_s(int* A, int left, int right){
  int pivotIndex = selectPivot(A, left, right);
	//printf("pivotidx = %d\n", pivotIndex);
	//printf("PivotIndex = %d\n", pivotIndex);
  swap_a(&A[left], &A[pivotIndex]); //swap the first element with the partition element

	pivotIndex = left; //the partition index becomes the index of the first element
	left = left+1;

	while (left <= right) {

    if (A[left]>A[pivotIndex]) { //if the number is greater than the pivot
			swap_a(&A[left],&A[right]); //move it to the right
			right = right-1;//decrease right
		}
    else left=left+1; //otherwise increase left
		//printArray(A,n);
  }

  swap_a(&A[right],&A[pivotIndex]);

  return right;
}

int quickselect(int* A, int left, int right, int k, const int n){

    int p = partition_s(A, left, right);
		//printf("%d\n",p);
    if (p == k) return p;

    else if (k < p) return quickselect(A, left, p-1, k, n);

    else return quickselect(A, p + 1, right, k, n);
}

int ksmallest(int* A, int n, int k){

    int left = 0, right = n - 1;
    return quickselect(A, left, right, k, n);
}