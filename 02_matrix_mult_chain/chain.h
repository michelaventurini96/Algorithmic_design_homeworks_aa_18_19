#ifndef __CHAIN__

void printMatrix(unsigned int** const matrix, const size_t size)
{
  for (size_t i = 0; i < size; i++) {
    printf("[ ");
    for (size_t j = 0; j < size; j++) {
      printf("%u\t", matrix[i][j]);
    }
    printf("\b\b\b\b]\n");
  }
}

void initMatrix(unsigned int** M, const size_t row, const size_t col)
{
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      M[i][j]=0;
    }
  }
}

unsigned int **allocate_matrix(const size_t rows,
                        const size_t cols)
{
   unsigned int** A = (unsigned int**) calloc(rows, sizeof(unsigned int*));

   for (size_t i=0; i<rows; i++) {
     A[i]=(unsigned int *)malloc(sizeof(unsigned int)*cols);
   }

   initMatrix(A, rows, cols);
   return A;
}

void deallocate_matrix(unsigned int **A, const size_t rows)
{
  for (size_t i=0; i<rows; i++) {
    free(A[i]);
  }

  free(A);
}

void MatrixChainAux(unsigned int* const P, unsigned int** m, unsigned int** s,
                                                const size_t i, const size_t j)
{
  //printf("MatrixChainAux\n");
  m[i][j]=INT_MAX;
  for (size_t k = i; k < j; k++) {
    unsigned int q = m[i][k]+m[k+1][j]+P[i]*P[k+1]*P[j+1];
    if (q < m[i][j]) {
      m[i][j]=q;
      s[i][j-1]=k+1;
    }
  }
}

unsigned int*** MatrixChain(unsigned int* const P, const size_t msize)
{
  unsigned int** m = allocate_matrix((size_t) msize, (size_t) msize);
  unsigned int** s = allocate_matrix((size_t) msize-1, (size_t) msize-1);

  for (size_t l = 1; l < msize; l++) {
    for (size_t i = 0; i < msize-l; i++) {
      size_t j=i+l;
      MatrixChainAux(P,m,s,i,j);
    }
  }
  unsigned int*** res = (unsigned int***) malloc(sizeof(unsigned int**)*2);
  res[0] = m;
  res[1] = s;
  return res;
}

#endif
