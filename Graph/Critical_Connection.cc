#include<bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> disc;
vector<int> low;
vector<bool> vis;
int timer;

void bridges(int u, vector<vector<int>>& graph, vector<vector<int>>& ans){
	disc[u] = low[u] = timer++;
	vis[u] = true;
	
	for(int& v : graph[u]){
		if(par[u] == v) continue;
		else if(vis[v] == true) low[u] = min(low[u],disc[v]);
		else{
			par[v] = u;
			bridges(v,graph,ans);
			low[u] = min(low[u],low[v]);
			if(low[v] > disc[u]) ans.push_back({u,v});
		}
	}
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
	vector<vector<int>> graph(n);
	for(auto it : connections){
		int u = it[0], v = it[1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	par = vector<int>(n);
	disc = vector<int>(n);
	low = vector<int>(n);
	vis = vector<bool>(n);
	timer = 0;
	int src = 0;
	vector<vector<int>> ans;
	
	bridges(src,graph,ans);
	return ans;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> graph(n,vector<int>(2));
	for(int i=0; i<m; i++){
		cin >> graph[i][0] >> graph[i][1];
	}
		
	vector<vector<int>> critical = criticalConnections(n,graph);
	for(auto it : critical){
		for(int j:it) cout << j << " ";
		cout << " | ";
	}
	cout << "\n";
	
	return 0;	
}
