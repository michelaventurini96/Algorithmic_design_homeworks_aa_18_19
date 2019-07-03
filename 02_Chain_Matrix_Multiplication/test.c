#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/chain.h"
#include "include/matrix.h"

size_t *build_dimensions(const size_t n) {
  size_t *dims = (size_t *)malloc(sizeof(size_t) * (n + 1));

  for (size_t i = 0; i < n + 1; i++) {
    dims[i] = rand() % 50;
  }

  return dims;
}

float ***build_problem_instance(const size_t *dims, const size_t n) {
  float ***A = (float ***)malloc(sizeof(float **) * n);

  for (size_t i = 0; i < n; i++) {
    A[i] = allocate_matrix(dims[i], dims[i + 1]);
  }

  return A;
}

/*matrices are multiplied in the order they are passed to th instance */
void naive_CMM(float ***problem_instance, size_t *dimensions_instance){
    
}

int main(){

      size_t *dims = build_dimensions(n);
  float ***As = build_problem_instance(dims, n);

  struct timespec requestStart, requestEnd;


}
