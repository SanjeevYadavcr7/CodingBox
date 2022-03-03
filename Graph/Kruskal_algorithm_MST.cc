#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
	return a[2] < b[2];
}

void makeSet(vector<int>& par, vector<int>& rank){
	int n = par.size();
	for(int i=0; i<n; i++){
	 	par[i] = i;
		rank[i] = 0;
	}
}

int findParent(int node, vector<int>& par){
	if(node == par[node]) return node;
	return par[node] = findParent(par[node],par);
}

void doUnion(int u, int v, vector<int>& par, vector<int>& rank){
	int u_par = findParent(u,par);
	int v_par = findParent(v,par);
	if(u_par == v_par) return;
	
	if(rank[u] < rank[v]) par[u] = v;
	else if(rank[u] > rank[v]) par[v] = u;
	else{
		par[v] = u;
		rank[u]++;
	}
}

int minCostToSupplyWater(int n, vector<vector<int>>& pipes){
	vector<int> par(n);
	vector<int> rank(n);
	makeSet(par,rank);
	
	sort(pipes.begin(),pipes.end(),cmp);
	
	int min_cost = 0;
	for(auto it : pipes){
		int u = it[0], v = it[1], cost = it[2];
		u = findParent(u,par);
		v = findParent(v,par);	
		if(u != v){
			min_cost += cost;
			doUnion(u,v,par,rank); 
		}
	}	
	return min_cost;
}

int main(){
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>>pipes(e,vector<int>(3));
    
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>pipes[i][j];
        }
    }
    
    cout<<minCostToSupplyWater(v,pipes) << "\n";
    
    return 0;
}
