#include "../include/bucket.h"


void initArray_float(float* const array, const size_t array_size){
	for (size_t i = 0; i < array_size; i++) {
		array[i] = (float) (rand()%1001)/1000;
	}
}

void printArray_float(float* const array, const size_t array_size) {
	for (size_t i = 0; i < array_size; i++) {
		printf("%f\t", array[i]);
	}
	printf("\n");
}

void printBucket(Node* const start_bucket){
    Node *temp = start_bucket;
		if(!temp) return;

    while (temp->next){
        printf("%f ", temp->n);
        temp = temp->next;
    }
		printf("%f\n", temp->n );
}

/* Function to append nodes in a given linked list */
void append(Bucket* start_bucket, const float value){
  //printf("inside append\n");
	Node* to_append = (Node*) malloc(sizeof(Node));
	to_append->n = value;
	to_append->next =NULL;

	if (start_bucket->first){
		Node* tmp = start_bucket->first;
		while(tmp->next) tmp = tmp->next;
		tmp->next = to_append;
	}
	else start_bucket->first = to_append;
}
/* function to swap data of two nodes a and b*/
void swapN(Node** a, Node** b){
    float temp = (*a)->n;
    (*a)->n = (*b)->n;
    (*b)->n = temp;
}

/* Bubble sort the given linked list */
void bubbleSort(Bucket* bucket){
  if (bucket->length>0){
    Node *tmp = bucket->first;

    while(tmp->next){
      if (tmp->n > tmp->next->n)
        swapN(&tmp, &(tmp->next));
      tmp = tmp->next;
    }
  }
		//return start_bucket;
}
/* Function to find element in a Bucket*/
float findElem(Node* const start_bucket, const size_t length, const size_t index){
	Node* tmp = start_bucket;
	size_t idx = 0;

  for (size_t i = 0; i < length && idx < index; i++){
    tmp = tmp -> next;
    idx++;
  }
	return tmp->n;
}

/*Function to fill a with ordered values*/
void fillArray(float* array, const size_t n, Bucket* const array_Buckets  ){
	int idx = 0;
	for (size_t i = 0; i < n; i++){
		for (size_t j = 0; j < array_Buckets[i].length ; j++){
			array[idx] = findElem( array_Buckets[i].first, array_Buckets[i].length, j);
      idx++;
		}
	}
}

void freeNode(Node* node){
    if(node->next != NULL)
        freeNode(node->next);

    free(node);
}

void freeBucket(Bucket b){
    if(b.first!=NULL)
        freeNode(b.first);
}

void freeArrayBuckets(Bucket* b, size_t n){
    for(size_t i=0;i<n;i++)
        freeBucket(b[i]);
    free(b);
}

Bucket newBucket(){
  Bucket b;
  b.first = NULL;
  b.length = 0;

  return b;
}

/*Function that implements Node Sort*/
void bucketSort(float* const a, const size_t n){

	// 1) Create n empty Nodes
	Bucket* array_Buckets = (Bucket*) malloc(n*sizeof(Bucket));
	for (size_t i = 0; i < n; i++) {
    array_Buckets[i] = newBucket();
  }
 
	// 2) Put array elements in different Nodes
	for (size_t i=0; i<n; i++){
		int bucket_idx = n*a[i]; // Index in Node
		array_Buckets[bucket_idx].length +=1;
    append(&array_Buckets[bucket_idx],a[i]);
	}

  //for(int i=0; i<n; i++) printBucket(array_Buckets[i].first);

	// 3) Sort individual Nodes
	for (size_t i=0; i<n; i++)
    bubbleSort(&array_Buckets[i]);
  
  //for(int i=0; i<n; i++) printBucket(array_Buckets[i].first);
	// 4) Concatenate all Nodes into a
	fillArray(a,n, array_Buckets);

	// 5) Free memory
	//for (size_t i = 0; i < n; i++) free(&array_Buckets[i]);
	freeArrayBuckets(array_Buckets, n);
}