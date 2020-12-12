#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
int V, graph[10][10];

int TSP(int graph[][10], int starting_node) {
	vector<int> vertex;
	for (int i = 0; i < V; i++) {
		if (i != starting_node) vertex.push_back(i);
	}

	int min_path = INT_MAX;
	do {
		int current_pw = 0;
		int k = starting_node;

		for (int i = 0; i < vertex.size(); i++) {
			current_pw += graph[k][vertex[i]];
			k = vertex[i];
		}

		// Assuming city 1 as the starting and ending node
		current_pw += graph[k][starting_node];
		min_path = min(min_path, current_pw);

	} while (next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

int main() {
	cout<<"\nEnter the number of vertices : ";
	cin>>V;
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			if(i == j) graph[i][j] = 0;
			else graph[i][j] = -1;
		}
	}

	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) {
			if(graph[i][j] == -1) {
				cout<<"\nEnter the distance between city "<<i + 1<<" and city "<<j + 1<<" : ";
				cin>>graph[i][j];
				graph[j][i] = graph[i][j];
			}
		}
	}

	int starting_node = 0;
	cout<<"\nThe minimum travelling distance is "<<TSP(graph, starting_node)<<endl;
	return 0;
}

// 0, 10, 15, 20 
// 10, 0, 35, 25
// 15, 35, 0, 30 
// 20, 25, 30, 0

// 10 + 25 + 30 + 15 = 80
