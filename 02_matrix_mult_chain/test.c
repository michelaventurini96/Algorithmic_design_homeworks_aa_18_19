#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <time.h>

#include "chain.h"

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
  return (e_time.tv_sec-b_time.tv_sec) + (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}

int main() {

  size_t MSIZE = 2;
  struct timespec b_time, e_time;

  for (size_t z = 0; z < 12; z++) {
    MSIZE = MSIZE<<1;

    //initialize vector of dimensiones P
    unsigned int* P = (unsigned int*) malloc(sizeof(unsigned int)*(MSIZE+1)) ;
    for (size_t i = 0; i < MSIZE+1; i++) {
      P[i]=(rand()%(10))+1;
    }

    clock_gettime(CLOCK_REALTIME, &b_time);
    unsigned int*** result = MatrixChain(P, MSIZE);
    clock_gettime(CLOCK_REALTIME, &e_time);

    // printf("Print matrix M\n");
    // printMatrix(result[0], MSIZE);
    // printf("\nPrint matrix S\n");
    // printMatrix(result[1], MSIZE-1);

    printf("\nExecution time - size %ld: ", MSIZE);
    printf("%lf s\n", get_execution_time(b_time, e_time));

    deallocate_matrix(result[0], MSIZE);
    deallocate_matrix(result[1], MSIZE-1);
    free(result);
    free(P);
  }
  return 0;
}
