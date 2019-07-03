#include<stdio.h>
#include<stdlib.h>

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
void countSort(int* a, int n, int exp){
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
        countSort(a, n, exp);
}

// A utility function to print an array
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
      printf("%d \n", a[i]);
}

// Driver program to test above functions
int main()
{
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a)/sizeof(a[0]);
    radixsort(a, n);
    printArray_int(a, n);
    return 0;
}
