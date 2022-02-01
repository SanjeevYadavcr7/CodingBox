#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

vector <int> dijkstra(int n, vector<vector<int>> adj[], int node){
    vector<int> dis(n,INT_MAX);
    vector<bool> vis(n,false);
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	
	dis[node] = 0;
	pq.push({0,node});
	
	while(!pq.empty()){
		auto it = pq.top();
		pq.pop();
		node = it.second;
		
		if(vis[node]) continue;
		vis[node] = true;
		
		for(vector<int> arr: adj[node]){
			int v = arr[0];
			int w = arr[1];
			if(dis[v] > dis[node] + w){
				dis[v] = dis[node] + w;
				pq.push({dis[v],v});
			}
		}
		
	}
	
	return dis;
}

int main(){
	int n,e,s;
	cin >> n >> e >> s;
	vector<vector<int>> adj[n];
	for(int i=0; i<e; i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	vector<int> dis = dijkstra(n,adj,s);
	for(int i:dis) cout << i << " ";
	cout << "\n";
	
	return 0;
}
