#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& vis, stack<int>& order, vector<vector<int>>& graph){
	vis[node] = true;
	for(int nei : graph[node]){
		if(!vis[nei]) dfs(nei,vis,order,graph);
	}
	order.push(node);
}

stack<int> doTopoSort(vector<vector<int>>& graph){
	int n = graph.size();
	stack<int> order;
	vector<bool> vis(n);
	
	for(int i=0; i<n; i++){
		if(!vis[i]) dfs(i,vis,order,graph);
	}
	return order;
}

vector<vector<int>> getGraphTranspose(vector<vector<int>>& graph){
	int n = graph.size();
	vector<vector<int>> transpose(n);
	for(int u=0; u<n; u++){
		for(int v=0; v<graph[u].size(); v++){
			transpose[graph[u][v]].push_back(u);
		}
	}
	return transpose;
}

void visit(int node, vector<bool>& vis, vector<vector<int>>& graph){
	if(vis[node]) return;
	
	vis[node] = true;
	for(int nei : graph[node]) visit(nei,vis,graph);
}

int getStronglyConnected(vector<vector<int>>& graph){
	int n = graph.size();
	stack<int> finishOrder = doTopoSort(graph);
	vector<vector<int>> graphTranspose = getGraphTranspose(graph);
	
	int cnt = 0;
	vector<bool> vis(n);
	while(!finishOrder.empty()){
		int node = finishOrder.top();
		finishOrder.pop();
		if(!vis[node]){
			visit(node,vis,graphTranspose);
			cnt++;
		}
	}
	
	return cnt;	
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	for(int i=0; i<m; i++){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	
	int components = getStronglyConnected(graph);
	cout << components << "\n";

	return 0; 
}
