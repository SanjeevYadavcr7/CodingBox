#include<bits/stdc++.h>
using namespace std;

void findShortestPath(int n, int e,vector<vector<int>>& edges){
	vector<int> dis(n,INT_MAX);
	dis[0] = 0;
	for(int i=0; i<e; i++){
		int s = edges[i][0], d = edges[i][1], w = edges[i][2];
		dis[d] = min(dis[d], dis[s]+w); 
	}
	
	for(int i=1; i<n; i++) cout << dis[i] << " ";
	cout <<"\n";
}

int main(){
	int n, e;
	cin >> n >> e;
	
	vector<vector<int>> edges(e, vector<int>(3));
	for(int i=0; i<e; i++){
		int src, dest, wei;
		cin >> src >> dest >> wei;
		edges[i][0] = src-1;
		edges[i][1] = dest-1;
		edges[i][2] = wei;
	}
	
	findShortestPath(n,e,edges);
	
	return 0;
}
