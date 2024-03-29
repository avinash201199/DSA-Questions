#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph) {
	vector<vector<int>> dist(graph);
	
	int V = graph.size();
	
	// Iterate over all phases 1,2,....,V
	for(int k=0;k<V;k++) {
		
		//Iterate over the 2-D matrix
		for(int i=0;i<V;i++) {
			for(int j=0;j<V;j++) {
				
				if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX) {
					if(dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				} 
			}
		}
	}
	
	for(int i=0;i<V;i++) {
		if(dist[i][i] < 0) {
			cout<<"Negative edge cycle detected\n";
			break;
		}
	}
	
	return dist;
	
}

int main() {
	vector<vector<int>> graph = {
		{0,INT_MAX,-2,INT_MAX},
		{4,0,3,INT_MAX},
		{INT_MAX,INT_MAX,0,2},
		{INT_MAX,-1,INT_MAX,0}
	};
	
	auto it = floyd_warshall(graph);
	
	for(int i=0;i<it.size();i++) {
		for(int j=0;j<it.size();j++) {
			cout<<it[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
