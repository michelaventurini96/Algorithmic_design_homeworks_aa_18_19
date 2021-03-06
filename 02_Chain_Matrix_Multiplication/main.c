#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <time.h>

#include "include/chain.h"
//#include "include/matrix.h"

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
  return (e_time.tv_sec-b_time.tv_sec) + (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}

unsigned int* initDim(const size_t msize){
    //initialize vector of dimensiones P
    unsigned int* P = (unsigned int*) malloc(sizeof(unsigned int)*(msize+1)) ;
    for (size_t i = 0; i <= msize; i++ ){
      P[i] = rand() % 50 ; 
    }
    return P;
}

int main() {

    size_t MSIZE = 4;
    
    for(size_t MSIZE = 4; MSIZE < 4096 ; MSIZE*=2){
	    struct timespec b_time, e_time;
	    unsigned int* P = initDim(MSIZE);

	    /*printf("Print P\n");
	    for (size_t i = 0; i < MSIZE+1; i++) {
	      printf("P[%ld] = %d\n",i,P[i] );
	    }*/

	    clock_gettime(CLOCK_REALTIME, &b_time);
	    unsigned int*** result = MatrixChain(P, MSIZE);
	    clock_gettime(CLOCK_REALTIME, &e_time);

	    /*printf("Print matrix M\n");
	    printMatrix(result[0], MSIZE);
	    printf("\nPrint matrix S\n");
	    printMatrix(result[1], MSIZE-1);*/

	    printf("\nExecution time: %lf s - size %ld: ", get_execution_time(b_time, e_time), MSIZE);

	    deallocate_matrix(result[0], MSIZE);
	    deallocate_matrix(result[1], MSIZE-1);
	    free(result);
	    free(P);
    }

  return 0;
}
