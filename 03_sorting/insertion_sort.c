#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <time.h>


#define BILLION 1E9
#define RANGE 255

/**************************************insertion sort and quicksort code********************************/

void initArray_int(int* const a, const size_t n){
  for (size_t i = 0; i < n; i++) {
    a[i] = rand()%999;
  }
}

void printArray_int(int* const a, const size_t n){
  printf("[ ");
  for (size_t i = 0; i < n; i++) printf("%d, ", a[i]);
  printf("\b\b ]\n");

}

// A utility function to swap two elements
void swap_int(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int* arr, int low, int high){
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++){
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int* arr, int low, int high){
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortBest(int* arr, int low, int high){
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = low+((high-low)/2);

        // Separately sort elements before
        // partition and after partition
        quickSortBest(arr, low, pi - 1);
        quickSortBest(arr, pi + 1, high);
    }
}

void insertionSort(int* a, const size_t n){
    size_t j;
    int key;
    for (size_t i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

/**********************************************************bucketsort code***********************************/
typedef struct Node{
	float n;
	struct Node* next;
} Node;

typedef struct Bucket{
  size_t length;
  struct Node* first;
} Bucket;

void initArray_float(float* const array, const size_t array_size){
	for (size_t i = 0; i < array_size; i++) {
		array[i] = (float) (rand()%101)/100;
	}
}

void printArray_float(float* const array, const size_t array_size) {
	for (size_t i = 0; i < array_size; i++) {
		printf("%f\t", array[i]);
	}
	printf("\n");
}

void printBucket(Node* const start_bucket){
    Node *temp = start_bucket;
		if(!temp) return;

    while (temp->next){
        printf("%f ", temp->n);
        temp = temp->next;
    }
		printf("%f\n", temp->n );
}

/* Function to append nodes in a given linked list */
void append(Bucket* start_bucket, const float value){
  //printf("inside append\n");
	Node* to_append = (Node*) malloc(sizeof(Node));
	to_append->n = value;
	to_append->next =NULL;

	if (start_bucket->first){
		Node* tmp = start_bucket->first;
		while(tmp->next) tmp = tmp->next;
		tmp->next = to_append;
	}
	else start_bucket->first = to_append;
}
/* function to swap data of two nodes a and b*/
void swap(Node** a, Node** b){
    float temp = (*a)->n;
    (*a)->n = (*b)->n;
    (*b)->n = temp;
}

/* Bubble sort the given linked list */
void bubbleSort(Bucket* bucket){
  if (bucket->length>0){
    Node *tmp = bucket->first;

    while(tmp->next){
      if (tmp->n > tmp->next->n)
        swap(&tmp, &(tmp->next));
      tmp = tmp->next;
    }
  }
		//return start_bucket;
}
/* Function to find element in a Bucket*/
float findElem(Node* const start_bucket, const size_t length, const size_t index){
	Node* tmp = start_bucket;
	size_t idx = 0;

  for (size_t i = 0; i < length && idx < index; i++){
    tmp = tmp -> next;
    idx++;
  }
	return tmp->n;
}

/*Function to fill a with ordered values*/
void fillArray(float* array, const size_t n, Bucket* const array_Buckets  ){
	int idx = 0, bucket_size;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < array_Buckets[i].length ; j++){
			array[idx] = findElem( array_Buckets[i].first, array_Buckets[i].length, j);
      idx++;
		}
	}
}

void freeNode(Node* node){
    if(node->next != NULL)
        freeNode(node->next);

    free(node);
}

void freeBucket(Bucket b){
    if(b.first!=NULL)
        freeNode(b.first);
}

void freeArrayBuckets(Bucket* b, size_t n){
    for(int i=0;i<n;i++)
        freeBucket(b[i]);
    free(b);
}

Bucket newBucket(){
  Bucket b;
  b.first = NULL;
  b.length = 0;

  return b;
}

/*Function that implements Node Sort*/
void bucketSort(float* const a, const size_t n){

	// 1) Create n empty Nodes
	Bucket* array_Buckets = (Bucket*) malloc(n*sizeof(Bucket));
	for (int i = 0; i < n; i++) {
    array_Buckets[i] = newBucket();
  }
 
	// 2) Put array elements in different Nodes
	for (int i=0; i<n; i++){
		int bucket_idx = n*a[i]; // Index in Node
		array_Buckets[bucket_idx].length +=1;
    append(&array_Buckets[bucket_idx],a[i]);
	}

  //for(int i=0; i<n; i++) printBucket(array_Buckets[i].first);

	// 3) Sort individual Nodes
	for (int i=0; i<n; i++)
    bubbleSort(&array_Buckets[i]);
  
  //for(int i=0; i<n; i++) printBucket(array_Buckets[i].first);
	// 4) Concatenate all Nodes into a
	fillArray(a,n, array_Buckets);

	// 5) Free memory
	//for (size_t i = 0; i < n; i++) free(&array_Buckets[i]);
	freeArrayBuckets(array_Buckets, n);
}

/********************************************************code for radix sort********************************************/

void initArray_r(int* const a, const size_t n){
  for (size_t i = 0; i < n; i++) {
    a[i] = 100 + rand() %99 ;
  }
}

// A utility function to get maximum value in arr[]
int getMax(int* a, int n){
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort_r(int* a, int n, int exp){
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (a[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (a[i]/exp)%10 ] - 1] = a[i];
        count[ (a[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int* a, int n){
    // Find the maximum number to know number of digits
    int m = getMax(a, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort_r(a, n, exp);
}

/**********************************************************code for counting sort**************************************/
// The main function that sort
// the given string arr[] in
// alphabatical order
void initArray_char(char *a, const size_t n){
  for(size_t i =0; i<n ; i++){
    a[i] = 'A' + (random() % 26);
  }
}

void printArray_char(const char const *a, const size_t n){
  for (size_t i = 0; i < n; i++)
  {
    printf("%c ", a[i]);
  }
  printf("\n");
  
}

void countSort(char* a, size_t n){
    // The output character array
    // that will have sorted arr
    char* output = (char*) malloc(sizeof(char)*n);

    // Create a count array to store count of inidividual
    // characters and initialize count array as 0
    int count[RANGE + 1], i;
    for (size_t i = 0; i < RANGE+1; i++) {
      count[i]=0;
    }

    // Store count of each character
    for(i = 0; i<n; ++i) ++count[a[i]];

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i) count[i] += count[i-1];

    for (i = n-1; i>=0; --i)  
    {  
        output[count[a[i]]-1] = a[i];  
        --count[a[i]];  
    }  


    for (i = 0; i<n; ++i)
        a[i] = output[i];
}

/*************************************************************code for heapsort*****************************************/
// To heapify a subtree rooted with node i which is
// an index in a. n is size of heap
void heapify(int* a, int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && a[l] > a[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
      int tmp=a[i];
      a[i]= a[largest];
      a[largest]=tmp;

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

// main function to do heap sort
void heapSort(int a[], int n){
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        int tmp=a[0];
        a[0]= a[i];
        a[i]=tmp;
  

        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}

/*****************************************************code for select**************************************************/
void swap_a(int* a, int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void copy(int* ar1 , const int* ar2, const int start, const int n){
	for (size_t i = start; i < start+n; i++) ar1[i-start]=ar2[i];
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

int selectPivot(int* const a, const int l, const int r, const int n){
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

int partition1(int* a, int low, int high, int n){
    int pivot = selectPivot(a, low, high, n);//a[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (a[j] <= pivot) {

            i++; // increment index of smaller element
            swap_a(a, &a[i], &a[j]);
        }
    }
    swap_a(a, &a[i + 1], &a[high]);
    return (i + 1);
}

int partition_s(int* A, int left, int right, const int n){
  int pivotIndex = selectPivot(A, left, right, n);
	//printf("pivotidx = %d\n", pivotIndex);
	//printf("PivotIndex = %d\n", pivotIndex);
  swap_a(A, &A[left], &A[pivotIndex]); //swap the first element with the partition element

	pivotIndex = left; //the partition index becomes the index of the first element
	left = left+1;

	while (left <= right) {

    if (A[left]>A[pivotIndex]) { //if the number is greater than the pivot
			swap_a(A,&A[left],&A[right]); //move it to the right
			right = right-1;//decrease right
		}
    else left=left+1; //otherwise increase left
		//printArray(A,n);
  }

  swap_a(A,&A[right],&A[pivotIndex]);

  return right;
}

int quickselect(int* A, int left, int right, int k, const int n){

    int p = partition_s(A, left, right, n);
		//printf("%d\n",p);
    if (p == k) return p;

    else if (k < p) return quickselect(A, left, p-1, k, n);

    else return quickselect(A, p + 1, right, k, n);
}

int ksmallest(int* A, int n, int k){

    int left = 0, right = n - 1;
    return quickselect(A, left, right, k, n);
}

/**********************************************Driver program to test insertion sort************************************/
int main(int argc, char* argv[]){

  struct timespec requestStart, requestEnd;
  double accum;

  printf("Size\t\tIns. Sort W\tIns. Sort B\tQuick Sort W\tQuick Sort B\tBucket Sort\tRadix Sort\tCounting Sort\tHeap Sort\tSelect Algo.\n");

  for(size_t N=10 ; N < 11 ; N *= 2) {

    //printf("%ld\t", N);

    /*array for insertion sort, quick sort, heap sort and select*/
    int* A = (int*) malloc(N*sizeof(int));
    initArray_int(A, N);
    printArray_int(A,N);
    
    clock_gettime(CLOCK_REALTIME, &requestStart);
    insertionSort(A, N);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    //printf("\t%lf", accum);
    printArray_int(A,N);

    clock_gettime(CLOCK_REALTIME, &requestStart);
    insertionSort(A, N);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    //printf("\t%lf", accum);
    printArray_int(A,N);
    
    initArray_int(A, N);
    clock_gettime(CLOCK_REALTIME, &requestStart);
    quickSort(A, 0, N-1);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) + (requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    //printf("\t%lf", accum);
    printArray_int(A,N);

    initArray_int(A, N);
    insertionSort(A, N);
    clock_gettime(CLOCK_REALTIME, &requestStart);
    quickSortBest(A, 0, N-1);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) + (requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    //printf("\t%lf", accum);
    printArray_int(A,N);
    
    //Array for bucketSort 
    float* B = (float*) malloc(N*sizeof(float));
    initArray_float(B, N);
    printArray_float(B,N);

    clock_gettime(CLOCK_REALTIME, &requestStart);
    bucketSort(B, N);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    //printf("\t%lf", accum);
    printArray_float(B,N);
    
    initArray_r(A, N);
    clock_gettime(CLOCK_REALTIME, &requestStart);
    radixsort(A, N);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    //printf("\t%lf", accum);
    printArray_int(A,N);
    
    char* C = (char*) malloc(N*sizeof(char));
    initArray_char(C, N);
    printArray_char(C, N);
    clock_gettime(CLOCK_REALTIME, &requestStart);
    countSort(C, N);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    //printf("\t%lf", accum);
    printArray_char(C, N);
      //printf("Sorted character array is:\n");
      //for (size_t i = 0; i < sizeof(a)/sizeof(char); i++) {
      //  printf("%c\n", a[i]);
      //}

    initArray_int(A, N);
    clock_gettime(CLOCK_REALTIME, &requestStart);
    heapSort(A, N);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    //printf("\t%lf", accum);
    printArray_int(A, N);

    int i = rand()%(N-1);
    initArray_int(A, N);
    clock_gettime(CLOCK_REALTIME, &requestStart);
    ksmallest(A, N, i);
    clock_gettime(CLOCK_REALTIME, &requestEnd);
    accum = (requestEnd.tv_sec - requestStart.tv_sec) +(requestEnd.tv_nsec - requestStart.tv_nsec) / BILLION;
    //printf("\t%lf\n", accum);

    //deallocate memory
    free(A);
    free(B);
    free(C);
  }
    return 0;
}
