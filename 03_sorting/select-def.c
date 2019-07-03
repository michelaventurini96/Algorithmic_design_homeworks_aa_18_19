#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int* const array, const size_t array_size) {
	for (size_t i = 0; i < array_size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void initArray(int* A, const size_t n){
  for (size_t i = 0; i < n; i++) A[i] = rand()%(n*2);
}

void swap(int* a, int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void copy(int* ar1 , const int* ar2, const int start, const int n){
	for (size_t i = start; i < start+n; i++) ar1[i-start]=ar2[i];
}

void copy_array(int* a , const int* b, const int size) {
  for (size_t i = 0; i < size; i++) a[i]=b[i];
}

void insertionSort(int* a, int n){
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
}

int selectPivot(int* const a, const int l, const int r, const int n){
	//if(l==r) return l;
	printArray(a,n);
  int chunk_size = (r-l+1)/5, res, median[5] = {0};
	int* tmp;
	if(chunk_size < 1){

		return l;
	}

  else
	 tmp = (int*) malloc(sizeof(int)*chunk_size);

	for (size_t i = 0; i < 5; i++) {//sort each chunk
		copy(tmp, a,i*chunk_size+l ,chunk_size);
		insertionSort(tmp, chunk_size);
		median[i] = tmp[(chunk_size/2)];
	}
	printf("%d\t%d\n",l,r);
	for (int i = l; i < r+1; i++) if(a[i] == median[3]) res = i; //find index of the median

  free(tmp);
	return res;
}

int partition1(int* a, int low, int high, int n){
    int pivot = selectPivot(a, low, high, n);//a[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (a[j] <= pivot) {

            i++; // increment index of smaller element
            swap(a, &a[i], &a[j]);
        }
    }
    swap(a, &a[i + 1], &a[high]);
    return (i + 1);
}

int partition(int* A, int left, int right, const int n){
  int pivotIndex = selectPivot(A, left, right, n);
	printf("pivotidx = %d\n", pivotIndex);
	//printf("PivotIndex = %d\n", pivotIndex);
  swap(A, &A[left], &A[pivotIndex]); //swap the first element with the partition element

	pivotIndex = left; //the partition index becomes the index of the first element
	left = left+1;

	while (left <= right) {

    if (A[left]>A[pivotIndex]) { //if the number is greater than the pivot
			swap(A,&A[left],&A[right]); //move it to the right
			right = right-1;//decrease right
		}
    else left=left+1; //otherwise increase left
		//printArray(A,n);
  }

  swap(A,&A[right],&A[pivotIndex]);

  return right;
}


int quickselect(int* A, int left, int right, int k, const int n){

    int p = partition(A, left, right, n);
		printf("%d\n",p);
    if (p == k) return p;

    else if (k < p) return quickselect(A, left, p-1, k, n);

    else return quickselect(A, p + 1, right, k, n);
}

int ksmallest(int* A, int n, int k){

    int left = 0, right = n - 1;
    return quickselect(A, left, right, k, n);
}

int main(int argc, char* argv[]){

  // if (argc<3) return 0;
  int dim_a=15;//, k = atoi(argv[1]);
  // srand(time(NULL));
  // if(atoi(argv[1])<3 || atoi(argv[2])<0){
  //   dim_a = 10, k = 3;
  // }
  // else {
  //   dim_a = atoi(argv[1]);
  //   k = atoi(argv[2]);
  // }
	// int* A = (int*) malloc(sizeof(int)*dim_a);
  // for (size_t i = 0; i < dim_a; i++) {
  //   A[i] = (dim_a-i)+(rand()%dim_a)*i;
  // }
  int* A = (int*) malloc(dim_a*sizeof(int));
  int* B = (int*) malloc(dim_a*sizeof(int));

  printf("A = ");
  initArray(A,dim_a);
  printArray(A,dim_a);
  copy_array(B, A, dim_a);
  printf("B = ");
  printArray(B,dim_a);
  insertionSort(B, dim_a);
  printArray(B,dim_a);
  

	for (int i = 0; i < dim_a; i++) {
		printf("the %d-th smallest element is %d (should be %d)\n", i, A[ksmallest(A, dim_a, i)], B[i]);
	}

	return 0;
}
