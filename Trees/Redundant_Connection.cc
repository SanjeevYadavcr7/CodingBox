#include<bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int>& par){
	if(node == par[node]) return node;
	return par[node] = findParent(par[node],par);
}

void doUnion(int a, int b, vector<int>& par, vector<int>& rank){
	if(rank[a] < rank[b]) par[a] = b;
	else if(rank[a] > rank[b]) par[b] = a;
	else{
		par[b] = a;
		rank[a]++;
	}
}

vector<int> findRedundantConnection(vector<vector<int>>& edges){
	int n = edges.size();
	vector<int> par(n+1);
	vector<int> rank(n+1,0);
	vector<int> ans;
	
	for(int i=1; i<=n; i++) par[i] = i;
	
	for(int i=0; i<n; i++){
		int a = edges[i][0], b = edges[i][1];
		int a_par = findParent(a,par);
		int b_par = findParent(b,par);
		
		if(a_par == b_par){
			ans = edges[i];
			break;
		}
		doUnion(a_par,b_par,par,rank);
	}	
	return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>pos(n,vector<int>(2));
    for (int i = 0; i < n; i++) {
      cin>>pos[i][0];
      cin>>pos[i][1];
    }

    vector<int>ans=findRedundantConnection(pos);
    cout<<ans[0]<<" "<<ans[1]<<endl;
	
	return 0;    
}
