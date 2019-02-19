#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <utility>
#include <iostream>

class Edge {
public:	
	int src;
	int dst;
	int weight;

	Edge(int s, int d, int w) : src(s), dst(d), weight(w) {}
};

class Compare {
public:
	bool operator() (const Edge* e1, const Edge* e2) const {
		return e1->weight < e2->weight;
	}
};

class Graph {
public:	
	int totalVertices;
	int totalEdges;

	// a set of all the vertices in the graph
	std::unordered_set<int> vertices;
	// vector to hold the edges
	std::vector<Edge*> edges;
	// adj: from -> (to , weight)
	std::unordered_map<int, std::vector<std::pair<int, int>>> adj;

	Graph() : totalVertices(0), totalEdges(0) {}

	~Graph() {
		for (auto& e : edges) {
			delete e;
		}
	}

	void addEdge(int from, int to, int w) {
		// vertices set
		vertices.insert(from);
		vertices.insert(to);
		
		// edges vector
		Edge* e = new Edge(from, to, w);
		edges.push_back(e);

		// adj map
		if (adj.find(from) == adj.end()) {
			adj.insert( std::make_pair( from, std::vector<std::pair<int, int>>() ) );
			adj[from].push_back(std::make_pair(to, w));
		}
		else {
			adj[from].push_back(std::make_pair(to, w));
		}

		if (adj.find(to) == adj.end()) {
			adj.insert( std::make_pair( to, std::vector<std::pair<int, int>>() ) );
			adj[to].push_back(std::make_pair(from, w));
		}
		else {
			adj[to].push_back(std::make_pair(from, w));
		}

		totalVertices = vertices.size();
		totalEdges    = edges.size(); 
	}

	void sortEdges() {
		std::sort(edges.begin(), edges.end(), Compare());
	}

	void printEdges() {
		for(auto& e : edges) {
			std::cout << "(" << e->src << ", " << e->dst << ", " << e->weight << ")" << std::endl;
		}
	}

	void printAdjMatrix() {
		std::unordered_map<int, std::vector<std::pair<int, int>>>::const_iterator it;
		for (it = adj.begin(); it != adj.end(); ++it) {
			std::cout << it->first << " -> ";
			for (auto& p : it->second) {
				std::cout << p.first << "(" << p.second << ")  ";
			}
			std::cout << std::endl;
		}
	}

};

#endif