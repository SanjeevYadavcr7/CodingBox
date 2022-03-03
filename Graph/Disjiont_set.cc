#include<bits/stdc++.h>
using namespace std;

vector<int> par(1000);
vector<int> rank(1000);

void makeSet(){
	int n = par.size();
	for(int i=0; i<n; i++){
		par[i] = i;
		rank[i] = 0;
	}
}

int findParent(int node){
	if(node == par[node]) return node;
	return par[node] = findParent(par[node]);
}

void union(int u, int v){
	u = findParent(u);
	v = findParent(v);
	if(u == v) continue;
	
	if(rank[u] < rank[v]) par[u] = v;
	else if(rank[u] > rank[v]) par[v] = u;
	else{
		par[v] = u;
		rank[u]++;
	}
	
}

int main(){
	
	makesSet();
	int m;
	cin >> m;
	while(m--){
		int u,v;
		union(u,v);	
	}

	return 0;
}
