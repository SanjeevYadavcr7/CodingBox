#include<bits/stdc++.h>
using namespace std;

int isNegativeWeightCycle(int n,vector<vector<int>>&edges){
	int e = edges.size();
	vector<int> dis(n, INT_MAX);
	dis[0] = 0;
	for(int i=0; i<e; i++){
		int s = edges[i][0], d = edges[i][1], w = edges[i][2];
		dis[d] = min(dis[d], dis[s]+w);
	}
	
	if(dis[0] == -1) return 1;
	for(int i=0; i<e; i++){
		int s = edges[i][0], d = edges[i][1], w = edges[i][2];
		if(dis[d] > dis[s]+w) return 1;
	}
	return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(3));
    
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges[i][0]=x;
        edges[i][1]=y;
        edges[i][2]=z;    
    }
    
    cout<<isNegativeWeightCycle(n, edges);
	
	return 0;
}
