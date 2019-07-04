#include "../include/dijkstra_heap.h"

void printGraph(Graph* g){
    int size = g->num_vertex;
    for(int i=0; i<size; i++)
    {
        Node x = g->nodes[i];
        if(x.dist == INT_MAX) printf("\nNode: %d - dist: /", x.id);
        else printf("\nNode: %d - dist: %d", x.id, x.dist);
        if((x.prev_node)!=NULL)
            printf(" - pred: %d", x.prev_node->id);
        else
            printf(" - pred: /");

    }
    printf("\n");
}

void printMatrix(int** matrix, int n_row, int n_col){
  for (int i = 0; i < n_row; i++) {
    for (int j = 0; j < n_col; j++) {
      if (matrix[i][j] == INT_MAX) printf("INF\t");
      else printf("%d\t",matrix[i][j]);
    }
    printf("\n");
  }
}

// routines of binary heap
bool isRoot(const size_t i){
  //return !(compareMax(i,0) && compareMin(i,0));
  return i==0;
}

size_t left( const size_t i){
  return 2*(i+1)-1;
}

size_t right( const size_t i){
  return 2*(i+1);
}

size_t parent(const size_t i){
  return (i-1)/2;
}

bool isValidNode(const BINARY_HEAP* const H, size_t const i){
  return H->size > i;
}

Node* findMin(BINARY_HEAP *H){
  return H->array[0];
}

int getRoot(){
  return 0;
}

void printHeap(BINARY_HEAP *H){
  if (H->size == 0) {
    printf("The heap is empty\n");
    return;
  }

  for (size_t i = 0; i < H->size; i++) {
    if (H->array[i]->dist == INT_MAX) printf("INF\t");
    else printf("%d\t",H->array[i]->dist);
  }
  printf("\nThe size of the heap is: %ld\n",H->size);
}

void swapHeap(Node** a, Node** b){

    int t_pos = (**a).pos;
    (**a).pos = (**b).pos;
    (**b).pos = t_pos;

    Node* temp = *a;
    *a = *b;
    *b = temp;
}

int emptyHeap(BINARY_HEAP* H) {return H->size==0; };

void decreaseKey(BINARY_HEAP *H, int i, int value){
    H->array[i]->dist = value;
    while (!isRoot(i) && H->array[i]<=H->array[parent(i)]){
      swapHeap(&(H->array[i]),&(H->array[parent(i)]));
      i = parent(i);
  }
}

void updateDistance(BINARY_HEAP* H, Node* v, int w){
    int pos = v->pos;
    decreaseKey(H, pos, w);
}

// for MinHeap
void minHeapify(BINARY_HEAP *H, size_t m){
  size_t k = -1;
  while (k !=m ){
    k = m;
    int children[2] = {left(k),right(k)}; //indices of right and left
    for (int j = 0; j < 2; j++)
      if (isValidNode(H, children[j]) && ((H->array[children[j]]->dist) <= (H->array[m]->dist)))
        m = children[j];
    if (k!=m)
      swapHeap(&(H->array[k]),&(H->array[m]));
  }
}

Node* extractMin(BINARY_HEAP *H){
  Node* min = H->array[0];
  H->array[0] = H->array[H->size-1];
  H->size--;
  minHeapify(H,0);
  return min;
}

BINARY_HEAP buildMinHeap(Node *sourceArray, int n){
   Node** node_pointers = (Node**) malloc(sizeof(Node*)*n);
   for(int i=0; i<n; i++){
       sourceArray[i].pos = i;
       node_pointers[i]=&(sourceArray[i]);
   }

   BINARY_HEAP H;
   H.size = n;
   H.array = node_pointers;

    int lastParentIdx = parent(H.size-1);
    for (int i =  lastParentIdx; i >= 0; i--) {
      minHeapify(&H,i);
    }
    return H;
}

void relax(BINARY_HEAP* q, Node* u, Node* v, int w){
    if(u->dist + w < v->dist)
    {
        updateDistance(q, v, u->dist + w);
        v->prev_node = u;
    }
}

void initializeGraph(Graph *g){
  for (int i = 0; i < g->num_vertex; i++) {
    g->nodes[i].id = i;
    g->nodes[i].dist = INT_MAX;
    g->nodes[i].prev_node = NULL;
  }
}

Node* getNode(Graph *g, int idNode){
  for (int i = 0; i < g->num_vertex; i++) {
    if (g->nodes[i].id == idNode) return &(g->nodes[i]);
  }
  return NULL;
}

int weight(Graph* g, Node* from, Node* to){
  return g->adj_list[from->id][to->id];
}

int lengthAdj(Graph *g, Node *u){
  int n = 0;
  for(int i=0; i<g->num_vertex; i++){
      if((g->nodes)[i].id == u->id) continue;
      n+=(weight(g,u,&(g->nodes)[i]))< INT_MAX;
  }
  return n;
}

Node** adjacents(Graph* g, Node* u, int n){
    Node** adj = (Node**) malloc(sizeof(Node*)*n);
    int a = 0;
    for(int i=0; i<g->num_vertex; i++)
    {
        int w = weight(g,u,&(g->nodes)[i]);
        if(w<INT_MAX && (g->nodes)[i].id != u->id)
                adj[a++] = &(g->nodes)[i];
    }

    return adj;
}

void dijkstraHeap(Graph *g, int start_node){
  
  initializeGraph(g);
  Node *s = getNode(g,start_node);
  s->dist = 0;

  BINARY_HEAP Q = buildMinHeap(g->nodes, g->num_vertex); //create the queue as a MinHeap
  BINARY_HEAP *Q_pointer = &Q; //create a Q_pointer

  while(!emptyHeap(Q_pointer)){
    Node* u = extractMin(Q_pointer);

    int n =  lengthAdj(g, u);
    Node** u_adj = adjacents(g, u, n);

    for(int i=0; i<n; i++)
      relax(Q_pointer, u, u_adj[i], weight(g, u, u_adj[i]));
    // //free(u_adj);
  }
  //free(Q_pointer);
}

