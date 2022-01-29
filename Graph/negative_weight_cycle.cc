#include<bits/stdc++.h>
using namespace std;

struct node{
	int s;
	int n;
	int wt;
	node(int src, int nei, int weight){
		s = src;
		n = nei;
		wt = weight;
	}
};

int isNegativeWeightCycle(int n,vector<node> edges, int src){
	vector<int> dis(n,INT_MAX);
	dis[src] = 0;
	for(int i=1; i<=n-1; i++){
		for(auto it : edges){
			int src = it.s, nei = it.n, weight = it.wt;
			if(dis[nei] > dis[src] + weight)
				dis[nei] = dis[src] + weight;
		}
	}	
	
	for(auto it : edges){
		int src = it.s, nei = it.n, weight = it.wt;
		if(dis[nei] > dis[src] + weight) return 1;
	}
	return 0;
}

int main(){
 	int n,e;
 	cin >> n >> e;
 	vector<node> edges;
 	for(int i=0; i<e; i++){
 		int s,n,w;
 		cin >> s >> n >> w;
 		edges.push_back(node(s,n,w));
 	}
 	
 	int src;
 	cin >> src;
 	
 	if(isNegativeWeightCycle(n,edges,src)) cout << "true";
 	else cout << "false";
 	cout << "\n";
 		
 	return 0;
}
