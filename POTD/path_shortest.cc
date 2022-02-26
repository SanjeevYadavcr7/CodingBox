#include<bits/stdc++.h>
using namespace std;

int shortestPathLength(vector<vector<int>>& graph){
	int n = graph.size(), all_vis_mask = (1 << n) - 1;
	int dist = 0;
	queue<pair<int,pair<int,int>>> nodes;
	set<pair<int,int>> vis;
	
	for(int curr_node = 0; curr_node < n; curr_node++){
		int curr_mask = (1 << i);
		nodes.push({curr_node, {0, curr_mask}});
		vis.insert({curr_node, curr_mask});
	}
	
	while(!nodes.empty()){
		auto it = nodes.front();
		int curr_node = it.first, dist = it.second.first, curr_mask = it.second.second;
		
		for(int nbr : graph[curr_node]){
			int new_mask = (curr_mask | (1 << nbr));
			
			if(new_mask == all_vis_mask) return dist+1;
			else if(vis.count({nbr,new_mask})) continue;
			else{
				nodes.push({nbr, {dist+1, new_mask}});
				vis.insert({nbr, new_mask});
			}
		}
	}
	return 0;
}

int main(){
	int n,m;
	cin >> n;
	vector<vector<int>> graph(n);
	for(int i=0; i<n; i++){
		cin >> m;
		vector<int> nei(m);
		for(int j=0; j<m; j++) cin >> nei[j];
		graph[i] = nei[i];  
	}
	
	int shortest_path = shortestPathLength(graph);	
	cout << shortest_path << "\n";
	
	return 0;
}	for(int curr_node = 0; curr_node<total_nodes; curr_node++){
