#include<bits/stdc++.h>
using namespace std;

class Edge{
	public:
		int src, nbr, wt;
		Edge(int src, int nbr, int wt){
			this->src = src;
			this->nbr = nbr;
			this->wt = wt;
		}
};

void getGroupsHelper(vector<Edge> graph[], int src, vector<int>& ans, bool vis[]){
	vis[src] = true;
	ans.push_back(src);
	for(Edge e:graph[src]){
		int nei = e.nbr;
		if(!vis[nei]) getGroupsHelper(graph,nei,ans,vis);
	}
}

void getGroups(vector<Edge> graph[], vector<vector<int>>& groups, int n){
	bool vis[n] = {false};
	for(int i=0;i<n;i++){
		if(!vis[i]){
			vector<int> ans;
			getGroupsHelper(graph,i,ans,vis);
			groups.push_back(ans);
		}
	}
}

int main(){
	int nodes,edges;
	cin>>nodes;
	vector<Edge> graph[nodes];
	cin>>edges;
	for(int i=0;i<edges;i++){
		int v1,v2,wt=0;
		cin>>v1>>v2;
		graph[v1].push_back(Edge(v1,v2,wt));
		graph[v2].push_back(Edge(v2,v1,wt));
	}
	
	vector<vector<int>> groups;
	getGroups(graph,groups,nodes);
	
	int g_size = groups.size(), pairs=0;
	for(int i=0;i<g_size;i++){
		for(int j=i+1;j<g_size;j++){
			int temp_pair = groups[i].size() * groups[j].size();
			pairs += temp_pair;	
		}
	}	
	cout<<pairs<<endl;
	return 0;
}





























