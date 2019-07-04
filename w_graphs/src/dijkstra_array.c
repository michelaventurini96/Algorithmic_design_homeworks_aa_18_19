#include<stdlib.h>
#include <stdio.h>
#include "../include/dijkstra_array.h"

// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int* dist, bool* sptSet, const size_t V) { 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (size_t v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

// A utility function to print the constructed distance array 
int printSolution(const int* const dist, const size_t V) {  
	for (size_t i = 0; i < V; i++){ 
		if(dist[i] == INT_MAX) printf("Node: %ld - dist: /\n", i); 
		else printf("Node: %ld - dist: %d\n", i, dist[i]); 
	}
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
int* dijkstra(int** graph, const size_t V, const int src) { 
	int* dist = (int*) malloc(V*sizeof(int)); // The output array. dist[i] will hold the shortest 
	// distance from src to i 

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
	// path tree or shortest distance from src to i is finalized 

	// Initialize all distances as INFINITE and stpSet[] as false 
	for (size_t i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	// Distance of source vertex from itself is always 0 
	dist[src] = 0; 

	// Find shortest path for all vertices 
	for (size_t count = 0; count < V - 1; count++) { 
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(dist, sptSet, V); 

		// Mark the picked vertex as processed 
		sptSet[u] = true; 

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (size_t v = 0; v < V; v++) {

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v] 
			if (!sptSet[v] && graph[u][v]!=INT_MAX && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
		}
	} 

	return dist;
	// print the constructed distance array 
	//printSolution(dist, V,V); 
} 

