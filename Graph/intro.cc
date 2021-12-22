#include<bits/stdc++.h>
using namespace std;

class Edge{
	public: 
		int src;
		int nbr;
		int wt;
		
		Edge(){
			src = nbr = wt = 0;
		}
		
		Edge(int src, int nbr, int wt){
			this->src = src;
			this->nbr = nbr;
			this->wt = wt;
		}
};

bool hasPath(vector<Edge> graph[], int src, int dest, bool vis[]){
	
	if(src == dest) return true;
	
	vis[src] = true;
	for(Edge edge : graph[src]){
		int nei = edge.nbr;
		if(!vis[nei]){
			if(hasPath(graph,nei,dest,vis)) return true;	
		}
	}
	return false;
}

int main(){
	int v,e;
	cin>>v;
	vector<Edge> graph[v];
	
	cin>>e;
	for(int i=0;i<e;i++){
		int v1,v2,wt;
		cin>>v1>>v2>>wt;
		graph[v1].push_back(Edge(v1,v2,wt));
		graph[v2].push_back(Edge(v2,v1,wt));
	}
	
	int src,dest;
	cin>>src>>dest;
	
	bool vis[v] = {false};
	
	if(hasPath(graph,src,dest,vis)) cout<<"true\n";
	else cout<<"false\n";
	
	return 0;
}
