#include <bits/stdc++.h>
#include "Graph.h"
#include "UnionFind.h"

using namespace std;

/*
Spanning Tree:
	- Sub-graph of a graph with edges visiting all the nodes
	- Does not contain cycle.

For a graph with e edges and v vertices,
there are (eCv-1 - #of cycles) possible spanning trees

Kruskal's algorithm:

1. Sort all the edges in increasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. 
	If cycle is not formed, include this edge. Else, discard it.
	Using Union-Find to detect cycle
3. Repeat step#2 until there are (V-1) edges in the spanning tree.

*/

void kruskalMST(Graph* gr) {
	if (gr == nullptr) {
		return;
	}

	// Edge vector to store MST
	vector<Edge*> result;

	// Sort the edges according to their weights
	gr->sortEdges();

	// Convert graph to union find
	UnionFind uf;

	unordered_set<int>::const_iterator it;
	for (it = (gr->vertices).begin(); it != (gr->vertices).end(); ++it) {
		uf.makeSet(*it);
	}

	// Index variable
	int at = 0;

	while (result.size() < (gr->totalVertices - 1)) {
		// Pick the next smallest edge
		Edge* e = gr->edges[at];

		int xRoot = uf.find(e->src);
		int yRoot = uf.find(e->dst);

		// If the edge doesn't cause a cycle, add it
		// Then union the source and destination
		if (xRoot != yRoot) {
			result.push_back(e);
			uf.performUnion(xRoot, yRoot);
		}

		at++;
	}

	// Print the minimum spanning tree
	cout << "Minimum Spanning Tree: " << endl;
	for (auto& e : result) {
		cout << e->src << " -- " << e->dst << "  (" << e->weight << ")" << endl; 
	}
	cout << endl;
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
	kruskalMST(gr);

	delete gr;

	return 0;
}
