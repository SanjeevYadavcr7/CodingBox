#include<bits/stdc++.h>
using namespace std;

struct node{
	int src;
	int nei;
	node(int src,int nei){
		this->src = src;
		this->nei = nei;
	}
};

void dfs(int curr_node, int cost, vector<bool>& vis, vector<node> edges, int& min_cost, int dest){
	if(curr_node == dest){
		min_cost = min(min_cost,cost);
		return;
	}
	if(vis[curr_node]) return;
	
	vis[curr_node] = true;
	int flag = 0;
	for(auto it : edges){
		int src = it.src, nei = it.nei;
		if(src == curr_node){
			dfs(nei,cost,vis,edges,min_cost,dest);		
			flag = 1;
		}
	}
	
	if(!flag){
		for(auto it : edges){
			int src = it.src, nei = it.nei;
			if(nei == curr_node){
				dfs(src,cost+1,vis,edges,min_cost,dest);		
			}
		}
	}
	vis[curr_node] = false;
}

int minEdgesToReverse(int n, vector<node> edges){
	vector<bool> vis(n,false);
	int min_cost = INT_MAX;
	dfs(1,0,vis,edges,min_cost,n);
	if(min_cost == INT_MAX) return -1;
	return min_cost;
}

int main(){
	int n,e;
	cin >> n >> e;
	vector<node> edges;
	for(int i=0; i<e; i++){
		int src,nei;
		cin >> src >> nei;
		edges.push_back(node(src,nei));
	}
	
	int min_edges = minEdgesToReverse(n,edges);
	cout << min_edges << "\n";
	
	return 0;
}
