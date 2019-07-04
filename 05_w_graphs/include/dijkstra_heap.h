#ifndef __HEAPH__
#define __HEAPH__

#include<stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include <time.h>

typedef struct Node{
  int id; //id of the Vertex
  int dist; //distance from the source
  int pos;
  struct Node * prev_node; //predecessor node (parent)
} Node; 

typedef struct binary_heap{
  Node** array;
  size_t size;
  //bool (*compare)(int, int);
} BINARY_HEAP;

typedef struct Graph{
  Node* nodes; //list of nodes
  int** adj_list;  //adjacency matrix
  int num_vertex; //number of vertex
} Graph;

void printGraph(Graph* g);
void printMatrix(int** matrix, int n_row, int n_col);
bool isRoot(const size_t i);
size_t left( const size_t i);
size_t right( const size_t i);
size_t parent(const size_t i);
bool isValidNode(const BINARY_HEAP* const H, size_t const i);
Node* findMin(BINARY_HEAP *H);
int getRoot();
void printHeap(BINARY_HEAP *H);
void swapHeap(Node** a, Node** b);
int emptyHeap(BINARY_HEAP* H);
void decreaseKey(BINARY_HEAP *H, int i, int value);
void updateDistance(BINARY_HEAP* H, Node* v, int w);
void minHeapify(BINARY_HEAP *H, size_t m);
Node* extractMin(BINARY_HEAP *H);
BINARY_HEAP buildMinHeap(Node *sourceArray, int n);
void relax(BINARY_HEAP* q, Node* u, Node* v, int w);
void initializeGraph(Graph *g);
Node* getNode(Graph *g, int idNode);
int weight(Graph* g, Node* from, Node* to);
int lengthAdj(Graph *g, Node *u);
Node** adjacents(Graph* g, Node* u, int n);
void dijkstraHeap(Graph *g, int start_node);

#endif //__HEAP__
