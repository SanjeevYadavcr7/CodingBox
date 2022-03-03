#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int getMinSupplyCost(vector<pair<int,int>> graph[], int n, int src, int cost){
	int path = 0;
	vector<bool> vis(n);
	priority_queue<pi, vector<pi>, greater<pi>> Q;
	
	//pair<int,int> = {cost,node}
	
	Q.push({0,src});
	while(!Q.empty()){
		auto it = Q.top();
		int cost = it.first;
		int node = it.second;
		Q.pop();
		
		if(vis[node]) continue;
		vis[node] = true;
		path += cost;
		
		/*
		cout << "Node = " << node << " | ";
		cout << "Cost = " << path << "\n";
		*/
		
		for(auto it : graph[node]) Q.push({it.second,it.first});
	}
	return path;
}

int minCostToSupplyWater(int n, vector<int>&wells, vector<vector<int>>& pipes){
	int src,cost = INT_MAX;
	vector<pair<int,int>> graph[n+1];
	for(int i=0; i<n; i++){
		int u = 0, v = i+1, w = wells[i];
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
		if(w < cost){
			cost = w;
			src = v;
		}
	}
	
	int edges = pipes.size();
	for(int i=0; i<edges; i++){
		int u = pipes[i][0], v = pipes[i][1], w = pipes[i][2];
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	
	int supply_cost = getMinSupplyCost(graph,n+1,src,cost);
	return supply_cost;
}


int main(){
    int v,e;
    cin>>v>>e;
    
    vector<int>wells(v);
    for(int i=0;i<v;i++) cin>>wells[i];
    
    vector<vector<int>>pipes(e,vector<int>(3));
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>pipes[i][j];
        }
    }
    
    cout<<minCostToSupplyWater(v, wells, pipes)<<"\n";
 	return 0;   
}
