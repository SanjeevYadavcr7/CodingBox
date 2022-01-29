#include<bits/stdc++.h>
using namespace std;

void dfs(int curr_node, vector<bool>& vis, stack<int>& stk, vector<int> adj[]){
	if(vis[curr_node]) return;
	vis[curr_node] = true;
	
	for(int nei : adj[curr_node]){
		dfs(nei,vis,stk,adj);
	}
	
	stk.push(curr_node);
}

bool has_cycle(int node, vector<bool>& vis, vector<int> adj[]){
	if(vis[node]) return true;
	
	vis[node] = true;
	
	for(int i : adj[node]){
		if(has_cycle(i,vis,adj)) return true;  
	}
	return false;
}

vector<int> getTopologicalSort(int n, vector<int> adj[]){
	vector<bool> vis(n,false);
	
	stack<int> stk;
	for(int i=0; i<n; i++){
		if(!vis[i]) dfs(i,vis,stk,adj);
	}
	
	vector<int> ans;
	while(!stk.empty()){
		ans.push_back(stk.top());
		stk.pop();
	}
	return ans;
}	

int main(){
	int n,e;
	cin >> n >> e;
	vector<int> adj[n];
	for(int i=0; i<e; i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	vector<bool> vis(n,false);
	if(has_cycle(0,vis,adj)){
		cout << "-1\n";
		return 0;
	} 	
	
	vector<int> order = getTopologicalSort(n,adj);
	for(int i=order.size()-1; i>=0; i--) cout << order[i] << " ";
	cout << "\n";
	
	return 0;
}
