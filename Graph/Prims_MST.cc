#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

string getMST(vector<pair<int,int>> graph[], int n){
	string path = "";
	vector<bool> vis(n);
	priority_queue<pi, vector<pi>, greater<pi>> Q;
	
	//pair<int,int> = {cost,node}
	
	Q.push({0,0});
	while(!Q.empty()){
		auto it = Q.top();
		int cost = it.first;
		int node = it.second;
		Q.pop();
		
		if(vis[node]) continue;
		vis[node] = true;
		path += to_string(node)+" ";
		
		for(auto it : graph[node]) Q.push({it.second,it.first});
	}
	return path;
}

int main(){
	int n,e;
	cin >> n >> e;
	vector<pair<int,int>> graph[n];
	for(int i=0; i<e; i++){
		int u,v,w;
		cin >> u >> v >> w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	
	string MST = getMST(graph,n);
	cout << MST << "\n";

	return 0;
}
