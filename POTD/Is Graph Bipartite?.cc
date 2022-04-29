#include<iostream>
#include<vector>
using namespace std;

bool canBeColored(int node, int color, vector<int>& vis, vector<int>& colors, vector<vector<int>>& graph) {
	vis[node] = 1;
	colors[node] = color;
	
	for(int nei : graph[node]){
		if(!vis[nei]) {
			if(!canBeColored(nei,color^1,vis,colors,graph)) return false;
		}
		else{
			if(colors[node] == colors[nei]) return false;
		}
	}
	return true;
}

bool isBipartite(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<int> vis(n), col(n);
	
	for(int i=0; i<n; i++){
		if(!vis[i] && !canBeColored(i,0,vis,col,graph)) return false;
	}
	return true;
}

int main() {
	int n,e;
	cin >> n;
	vector<vector<int>> graph(n);
	for(int i=0; i<n; i++){
		cin >> e;
		vector<int> nei(e);
		for(int j=0; j<e; j++) cin >> nei[j];
		graph[i] = nei; 
	}
	
	cout << (isBipartite(graph) ? "true" : "false") << endl;
	
	return 0;
}
