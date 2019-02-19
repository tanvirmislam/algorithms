#include <bits/stdc++.h>
#include "Graph.h"

using namespace std;

# define INF 0x3f3f3f3f // https://sxkdz.org/why-programmers-like-to-set-infinity-to-0x3f3f3f3f/

/*
Algorithm (from GeeksForGeeks):

1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (vertex, weight).

3) Insert source vertex into pq and make its
   distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array: all shortest paths. 

*/

class CompareMinHeap {
public:
	bool operator() (const pair<int, int> p1, const pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

void shortestPath(Graph *gr, int source) {
	// Create a PQ
	// PQ elements are (dst, weight)
	priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMinHeap> pq;

	// Distances to all vertices
	unordered_map<int, int> distMap;
	for (unordered_set<int>::const_iterator it = gr->vertices.begin(); it != gr->vertices.end(); ++it) {
		distMap.insert(make_pair(*it, INF));
	}

	// Start from source 
	// Distance to the source is zero.
	pq.push(make_pair(source, 0));
	distMap[source] = 0;

	// Start loop
	while (!pq.empty()) {
		int currentV = pq.top().first;
		int currentW = pq.top().second;
		pq.pop();

		// get all the adjacent vertices of the current vertex
		for (auto& p : gr->adj[currentV]) {
			int v = p.first;
			int w = p.second;

			if (distMap[v] > distMap[currentV] + w) {
				distMap[v] = distMap[currentV] + w;
				pq.push(make_pair(v, distMap[v]));
			}
		}
	}

	cout << "--------------------" << endl;
	cout << "Vertex      Distance" << endl;
	cout << "--------------------" << endl;
	for (unordered_map<int, int>::const_iterator it = distMap.begin(); it != distMap.end(); ++it) {
		cout <<  "  " << it->first << "            " << it->second << endl;
	}
}

Graph* test1() {
	Graph* gr = new Graph();

	gr->addEdge(0, 1, 4); 
	gr->addEdge(0, 7, 8); 
	gr->addEdge(1, 2, 8); 
	gr->addEdge(1, 7, 11); 
	gr->addEdge(2, 3, 7); 
	gr->addEdge(2, 8, 2); 
	gr->addEdge(2, 5, 4); 
	gr->addEdge(3, 4, 9); 
	gr->addEdge(3, 5, 14); 
	gr->addEdge(4, 5, 10); 
	gr->addEdge(5, 6, 2); 
	gr->addEdge(6, 7, 1); 
	gr->addEdge(6, 8, 6); 
	gr->addEdge(7, 8, 7); 

	/*
	Answer:

	Vertex   Distance from Source
	0          0
	1          4
	2          12
	3          19
	4          21
	5          11
	6          9
	7          8
	8          14

	*/

	return gr;
}


int main() {
	Graph* gr = test1();

	shortestPath(gr, 0);

	delete gr;

	return 0;
}
