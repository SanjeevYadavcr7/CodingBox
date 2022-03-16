#include<bits/stdc++.h>
using namespace std;

bool desc(vector<int>& a, vector<int>&b);
int findParent(int node, vector<int>& par);
bool Union(int u, int v, vector<int>& par, vector<int>& rank);

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
	vector<int> par_a(n+1);
	vector<int> par_b(n+1);
	vector<int> rank_a(n+1,0);
	vector<int> rank_b(n+1,0);
	int merged_a = 1, merged_b = 1;
	int removed = 0;
	
	sort(edges.begin(),edges.end(),desc);
	for(int i=0; i<=n; i++) par_a[i] = par_b[i] = i;
		
		
	for(auto edge : edges){
		int type = edge[0];
		if(type == 3){
			bool isMerged_a = Union(edge[1],edge[2],par_a,rank_a);
			bool isMerged_b = Union(edge[1],edge[2],par_b,rank_b); 
			
			if(isMerged_a) merged_a++;
			if(isMerged_b) merged_b++;
			
			if(!isMerged_a && !isMerged_b) removed++;
		}
		else if(type == 2){
			bool isMerged_b = Union(edge[1],edge[2],par_b,rank_b); 			
			if(isMerged_b) merged_b++;		
			else removed++;
		}
		else{
			bool isMerged_a = Union(edge[1],edge[2],par_a,rank_a); 			
			if(isMerged_a) merged_a++;		
			else removed++;		
		}
	}
	
	if(merged_a != n || merged_b != n) return -1;
	return removed;
} 

int main(){
	int n, m;
    cin >> n >> m;
    vector<vector<int>>edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
      cin >> edges[i][0];
      cin >> edges[i][1];
      cin >> edges[i][2];
    }
    cout<<maxNumEdgesToRemove(n, edges);
	
	return 0;
}



































int findParent(int node, vector<int>& par){
 	if(node == par[node]) return node;
 	return par[node] = findParent(par[node],par);
}

bool Union(int u, int v, vector<int>& par, vector<int>& rank){
	u = findParent(u,par);
	v = findParent(v,par);
	if(u != v){
		if(rank[u] > rank[v]) par[v] = u;
		else if(rank[u] < rank[v]) par[u] = v;
		else{
			par[v] = u;
			rank[u]++;
		}
		return true;
	}
	return false;
}

bool desc(vector<int>& a, vector<int>&b){
	return a[0] > b[0];
}
