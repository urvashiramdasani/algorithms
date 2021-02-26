// Practical 4 - Write a program to implement single source shortest path algorithm.

// Import all libraries
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> // For INT_MAX

using namespace std;

// Function to print the graph
void printGraph(vector< vector< int > > &G) {
	int n = G.size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cout << G[i][j] << " ";
		cout << endl;
	}
}

// Function to assign weight to edges of graph
void insertEdge(vector< vector< int > > &G) {
	while(1) {
		int u, v, w; cin >> u >> v >> w;
		if(u == -1 || v == -1 || w == -1) break;
		G[u][v] = w;     // Not assigning w to (v, u) due to directed graph
	}
}

// Utility function to compute minimum distance node from all nodes
int minDistance(vector< int > &path, vector< bool > &visited) {
	int min = INT_MAX, index;
	int V = path.size();
	for(int i = 0; i < V; i++) {
		if(visited[i] == false && path[i] <= min) {
			min = path[i];
			index = i;
		}
	}
	return index;
}

// Function to compute single source shortest path
void dijkstra(vector< vector< int > > &G, int V) {

	// Initialize a vector to store path lengths as INFINITY
	vector< int > path (V, INT_MAX);
	vector < bool > visited (V, false);

	path[0] = 0; // Distance from source to source vertex
	for(int i = 0; i < V - 1; i++) {
		int u = minDistance(path, visited);
		visited[u] = true;

		for(int v = 0; v < V; v++) {
			if(!visited[v] && G[u][v] && path[u] != INT_MAX && path[u] + G[u][v] < path[v]) path[v] = path[u] + G[u][v];
		}
	}

	// Print the result
	cout << "\nDistance from source : ";
	for(int i = 0; i < V; i++) {
		cout << "0 -> " << i << " = " << path[i] << endl;
	}
}

int main() {

	// Input the number of vertices
	cout << "Enter the number of vertices : ";
	int V; cin >> V;

	// Initialize a 2d vector of size V with zero
	vector< vector< int > > G(V, vector< int >(V, 0));
	
	// Assign weight to edges of graph
	cout << "\nEnter an edge with its weight (u, v, w) [Enter -1 to end] : ";
	insertEdge(G);

	// Print the graph
	cout << "\nThe Graph entered is : \n";
	printGraph(G);

	// Compute Single Source Shortest Path
	dijkstra(G, V);
}
