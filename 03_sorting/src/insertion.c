#include "../include/insertion.h"
#include "../include/select.h"

void initArray_int(int* a, const size_t n){
  for (size_t i = 0; i < n; i++) {
    a[i] = rand()%999;
  }
}

void printArray_int(const int* const a, const size_t n){
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
/* int partition (int* arr, int low, int high){
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
}*/

void quickSort(int* arr, int low, int high){
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition_s(arr, low, high);

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
    int j;
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