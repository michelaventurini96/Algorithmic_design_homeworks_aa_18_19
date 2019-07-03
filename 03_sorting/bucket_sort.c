#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	float n;
	struct Node* next;
} Node;

void initArray(float* const array, const size_t array_size){
	for (size_t i = 0; i < array_size; i++) {
		array[i] = (float) (rand()%101)/100;
	}
}

void printArray(float* const array, const size_t array_size) {
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
Node* append(Node* start_bucket, const float value){
	Node* to_append = (Node*) malloc(sizeof(Node));
	to_append->n = value;
	to_append->next =NULL;

	if (start_bucket){
		Node* tmp = start_bucket;
		while(tmp->next) tmp = tmp->next;
		tmp->next = to_append;
	}
	else start_bucket = to_append;
	return start_bucket;
}
/* function to swap data of two nodes a and b*/
void swap(Node* a, Node* b){
    float temp = a->n;
    a->n = b->n;
    b->n = temp;
}
/* Function to return the size of a list*/
size_t bucketSize(Node* const start_bucket){
	size_t bucket_size = 0;
	if(!start_bucket) return bucket_size;
	Node *temp = start_bucket;
	while (temp->next) {
		temp=temp->next;
		bucket_size++;
	}
	bucket_size++;
	return bucket_size;
}
/* Bubble sort the given linked list */
Node* bubbleSort(Node* start_bucket){
		int swapped, i;
    Node *tmp;
    Node *lptr = NULL;

    if (!start_bucket) return start_bucket;
    do{
        swapped = 0;
        tmp = start_bucket;

        while (tmp->next != lptr){
            if (tmp->n > tmp->next->n){
                swap(tmp, tmp->next);
                swapped = 1;
            }
            tmp = tmp->next;
        }
        lptr = tmp;
    }
    while (swapped);
		return start_bucket;
}
/* Function to find element in array of Nodes*/
float findElem(Node* const start_bucket, const size_t bucket_size){
	Node* tmp = start_bucket;
	size_t idx = 0;
	while (idx++ < bucket_size) tmp=tmp->next;
	return tmp->n;
}
/*Function to fill a with ordered values*/
void fillArray(float* array, Node** const array_Buckets, const size_t array_size ){
	int idx = 0, bucket_size;
	for (int i = 0; i < array_size; i++){
		bucket_size = bucketSize(array_Buckets[i]);
		//printf("Size of chunk %d is %d\n",i, tmp_size );
		for (int j = 0; j < bucket_size; j++){
			array[idx++] = findElem( array_Buckets[i], j);
		}
	}
}
/*Function that implements Node Sort*/
void bucketSort(float* const array, const size_t array_size){
	// 1) Create n empty Nodes
	Node** array_Buckets = (Node**) malloc(array_size*sizeof(Node*));
	for (size_t i = 0; i < array_size; i++) array_Buckets[i] = NULL;

	// 2) Put array elements in different Nodes
	for (int i=0; i<array_size; i++){
		int bucket_idx = array_size*array[i]; // Index in Node
		array_Buckets[bucket_idx] = append(array_Buckets[bucket_idx],array[i]);
	}

	// 3) Sort individual Nodes
	for (int i=0; i<array_size; i++) array_Buckets[i] = bubbleSort(array_Buckets[i]);

	// 4) Concatenate all Nodes into a
	fillArray(array, array_Buckets, array_size);

	// 5) Free memory
	for (size_t i = 0; i < array_size; i++) free(array_Buckets[i]);
	free(array_Buckets);
}

int main(int argc, char* argv[]){
	if(argc<2) return 0;
	size_t array_size = (size_t) atoi(argv[1]);
	array_size < 10 ? array_size=10 : array_size;

	float* array_to_sort = (float*) malloc(sizeof(float)*array_size);

	initArray(array_to_sort, array_size);
	printf("Array to be sorted:\n");
	printArray(array_to_sort,array_size);

	bucketSort(array_to_sort, array_size);

	printf("Sorted array:\n");
	printArray(array_to_sort,array_size);

	free(array_to_sort);
	return 0;
}
