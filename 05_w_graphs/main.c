#include <time.h>
#include "include/dijkstra_array.h"
#include "include/dijkstra_heap.h"

// routine to get time of execution
double getExecutionTime(const struct timespec b_time, const struct timespec e_time){
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}

int** initMatrix(size_t V){
  int** adj_matrix = (int**) malloc(sizeof(int*)*V);
  for (size_t i = 0; i < V; i++)
    adj_matrix[i] = (int*)malloc(sizeof(int)*V);

  for(size_t i=0; i<V; i++){
    for (size_t j = 0; j < V; j++){
      adj_matrix[i][j]=INT_MAX;
    }
  }
  
    adj_matrix[0][1] = 1;
    adj_matrix[0][2] = 5;
    adj_matrix[1][5] = 15;
    adj_matrix[2][3] = 2;
    adj_matrix[3][4] = 1;
    adj_matrix[4][5] = 3;

  return adj_matrix;

}

int main() {
  struct timespec b_time, e_time;
  double arrayTime, heapTime; // variables to time executions
  
  for (size_t V = 5; V <= 7; V++)
  {
    printf("# of vertex: %ld\n", V);

    int** adj_matrix = initMatrix(V);

    printf("**** Adj Matrix ****\n");
    printMatrix(adj_matrix,V,V);
    
    // array based implementation

    printf("\n**** Array solution ****\n");
    
    clock_gettime(CLOCK_REALTIME, &b_time);
    int* solution = dijkstra(adj_matrix, V, 0); 
    clock_gettime(CLOCK_REALTIME, &e_time);
    
    arrayTime = getExecutionTime(b_time,e_time);
    printf("Time = %lf\n",heapTime );

    printSolution(solution, V);
    
    // heap based implementation

    Graph g;
    g.num_vertex=V;
    g.adj_list = adj_matrix;
    g.nodes = (Node*) malloc(sizeof(Node)*V);
  
    printf("\n**** Heap solution ****\n");
    
    clock_gettime(CLOCK_REALTIME, &b_time);
    dijkstraHeap(&g, 0);
    clock_gettime(CLOCK_REALTIME, &e_time);
    
    heapTime = getExecutionTime(b_time,e_time);
    printf("Time = %lf\n",heapTime );
    
    printGraph(&g);

  }

	return 0;
}
