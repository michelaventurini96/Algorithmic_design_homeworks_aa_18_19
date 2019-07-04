#include "../include/count.h"

// The main function that sort
// the given string arr[] in
// alphabatical order
void initArray_char(char *a, const size_t n){
  for(size_t i =0; i<n ; i++){
    a[i] = 'A' + (random() % 26);
  }
}

void printArray_char(const char* const a, const size_t n){
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
    for(size_t i = 0; i<n; ++i) ++count[(int)a[i]];

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i) count[i] += count[i-1];

    for (i = n-1; i>=0; --i)  
    {  
        output[count[(int)a[i]]-1] = a[i];  
        --count[(int)a[i]];  
    }  


    for (size_t i= 0; i<n; ++i)
        a[i] = output[i];
}