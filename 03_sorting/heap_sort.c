// C program for implementation of Heap Sort
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

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

void init_arr(int* const a, const size_t n){
  for (size_t i = 0; i < n; i++) {
    a[i] = rand()%100;
  }
}

void printArray(int* const a, const size_t n)
{
  printf("[ ");
  for (size_t i = 0; i < n; i++) printf("%d, ", a[i]);
  printf("\b\b ]\n");

}

// Driver program
int main(int argc, char* argv[])
{
  int N = atoi(argv[1]);
  int* a = (int*) malloc(N*sizeof(int));
  init_arr(a, N);

  heapSort(a, N);
  printArray(a, N);
}
