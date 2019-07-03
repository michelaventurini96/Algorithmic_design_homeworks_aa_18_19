#include<stdio.h>
#include<stdlib.h>


#define RANGE 255

// The main function that sort
// the given string arr[] in
// alphabatical order
void countSort(char* a, size_t n)
{
    // The output character array
    // that will have sorted arr
    char* output = (char*) malloc(sizeof(char)*n);

    // Create a count array to store count of inidividul
    // characters and initialize count array as 0
    int count[RANGE + 1], i;
    for (size_t i = 0; i < RANGE+1; i++) {
      count[i]=0;
    }

    // Store count of each character
    for(i = 0; a[i]; ++i) ++count[a[i]];

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i) count[i] += count[i-1];

    // Build the output character array
    for (i = 0; a[i]; ++i)
    {
        output[count[a[i]]-1] = a[i];
        --count[a[i]];
    }

    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; a[i]; ++i)
        a[i] = output[i];
}

// Driver  code
int main()
{
    char a[] = "geeksforgeeks";

    countSort(a, sizeof(a)/sizeof(char));
    printf("Sorted character array is:\n");
    for (size_t i = 0; i < sizeof(a)/sizeof(char); i++) {
      printf("%c\n", a[i]);
    }
    return 0;
}
