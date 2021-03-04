// Practical 6 - Write a program to implement all source shortest path algorithm.

// Name : Urvashi Ramdasani
// Roll Number : 18BCE247

// Import all libraries
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9999

using namespace std;

// Function to print the graph
void printGraph(vector< vector< int > > &G) {
	int V = G.size();
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			if(G[i][j] == INF) cout << "INF ";
			else cout << G[i][j] << " ";
		}
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

void floyd_warshall(vector< vector< int > > G, int V) {
	vector< vector< int > > sol = G;

	for(int k = 0; k < V; k++) {
		for(int i = 0; i < V; i++) {
			for(int j = 0; j < V; j++) {
				if(sol[i][k] + sol[k][j] < sol[i][j]) sol[i][j] = sol[i][k] + sol[k][j];
			}
		}
	}

	cout << "\nDistance from all vertices : \n";
	printGraph(sol);
}

int main() {

	// Input the number of vertices
	cout << "Enter the number of vertices : ";
	int V; cin >> V;

	// Initialize a 2d vector of size V with INF
	vector< vector< int > > G(V, vector< int >(V, INF));

	for(int i = 0; i < V; i++) G[i][i] = 0;
	
	// Assign weight to edges of graph
	cout << "\nEnter an edge with its weight (u, v, w) [Enter -1 to end] : ";
	insertEdge(G);

	// Print the graph
	cout << "\nThe Graph entered is : \n";
	printGraph(G);

	// Compute Single Source Shortest Path
	floyd_warshall(G, V);
}

/* Output : 
Enter the number of vertices : 4

Enter an edge with its weight (u, v, w) [Enter -1 to end] : 0 1 5
1 2 1
2 3 3
2 0 8
3 0 2
-1 -1 -1

The Graph entered is : 
0 5 INF INF 
INF 0 1 INF 
8 INF 0 3 
2 INF INF 0 

Distance from all vertices : 
0 5 6 9 
6 0 1 4 
5 10 0 3 
2 7 8 0

*/
