#ifndef __HEAPA__
#define __HEAPA__

#include <limits.h> 
#include <stdio.h> 
#include<stdbool.h>

int minDistance(int* dist, bool* sptSet, const size_t V);
int printSolution(const int* const dist, const size_t V);
int* dijkstra(int** graph, const size_t V, const int src);

#endif