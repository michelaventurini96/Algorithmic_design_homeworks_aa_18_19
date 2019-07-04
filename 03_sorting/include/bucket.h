#ifndef __BUCKET__
#define __BUCKET__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

typedef struct Node{
	float n;
	struct Node* next;
} Node;

typedef struct Bucket{
  size_t length;
  struct Node* first;
} Bucket;

void initArray_float(float* const array, const size_t array_size);
void printArray_float(float* const array, const size_t array_size);
void printBucket(Node* const start_bucket);
void append(Bucket* start_bucket, const float value);
void swapN(Node** a, Node** b);
void bubbleSort(Bucket* bucket);
float findElem(Node* const start_bucket, const size_t length, const size_t index);
void fillArray(float* array, const size_t n, Bucket* const array_Buckets  );
void freeNode(Node* node);
void freeBucket(Bucket b);
void freeArrayBuckets(Bucket* b, size_t n);
Bucket newBucket();
void bucketSort(float* const a, const size_t n);

#endif