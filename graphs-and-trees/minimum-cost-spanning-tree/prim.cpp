#include <bits/stdc++.h>
#include "Graph.h"
#include "UnionFind.h"

using namespace std;

# define INF 0x3f3f3f3f // https://sxkdz.org/why-programmers-like-to-set-infinity-to-0x3f3f3f3f/


/*
Spanning Tree:
	- Sub-graph of a graph with edges visiting all the nodes
	- Does not contain cycle.

For a graph with e edges and v vertices,
there are (eCv-1 - #of cycles) possible spanning trees

Prim's Algorithm:

1) 	Create a set that keeps track of vertices already included in MST.

2) 	Assign a key value to all vertices in the input graph. 
	Initialize all key values as INFINITE. 
	Assign key value as 0 for the first vertex so that it is picked first.

3) 	While the set of included MST doesn’t include all vertices
		a) 	Pick a vertex u which is not there in the set and has minimum key value.
		b) 	Include u to the set.
		c) 	Update key value of all adjacent vertices of u. 
			To update the key values, iterate through all adjacent vertices. 
			For every adjacent vertex v, 
				if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v

*/

class CompareMinHeap {
public:
	bool operator() (const pair<int, int> p1, const pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

void primMST(Graph* gr, int start) {
	// Track visited
	unordered_set<int> visited; 
	visited.insert(start);

	// Priority queue to have access to edge with minimum weight
	// PQ elements are (dst, weight)
	priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMinHeap> pq;

	// Save available paths to the PQ, take the smallest weighted path
	// Start loop
	int at = start;
	while (visited.size() < gr->totalVertices) {
		// cout << "at " << at << endl;
		for (auto& p : gr->adj[at]) {
			if (visited.find(p.first) == visited.end()) {
				// cout << "pushing path from " << at << " to " << p.first << " (" << p.second << ")" << endl;
				pq.push(p);	
			}
		}

		pair<int, int> currentPath = pq.top();
		pq.pop();

		while (visited.find(currentPath.first) != visited.end()) {
			currentPath = pq.top();
			pq.pop();			
		}

		visited.insert(currentPath.first);

		cout << at << " -- " << currentPath.first << "  (" << currentPath.second << ")" << endl;

		at = currentPath.first;
	}
}




Graph* test1() {
	// Making graph:
	//    10 
	//  0----1 
	//  | \  | 
	// 6| 5\ |15 
	//  |   \| 
	//  2----3 
	//    4

	int v = 4;
	int e = 5;
	Graph* gr = new Graph();

	gr->addEdge(0, 1, 10);
	gr->addEdge(0, 2, 6);
	gr->addEdge(0, 3, 5);
	gr->addEdge(1, 3, 15);
	gr->addEdge(2, 3, 4);

	return gr;
}


int main() {
	Graph* gr = test1();

	// gr->printAdjMatrix();
	primMST(gr, 0);

	delete gr;

	return 0;
}
