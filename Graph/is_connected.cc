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

void isConnectedHelper(vector<Edge> graph[], int src, bool vis[]){
	vis[src] = true;
	for(Edge e:graph[src]){
		int nei = e.nbr;
		if(!vis[nei]) isConnectedHelper(graph,nei,vis);
	}
}

bool isConnected(vector<Edge> graph[], int total_nodes){
	
	bool vis[total_nodes] = {false};
   	int total_components=0;

	for(int curr_node = 0; curr_node < total_nodes; curr_node++){
		if(!vis[curr_node]){
			total_components++;
			isConnectedHelper(graph,curr_node,vis);
		}
	}

	if(total_components>1) return false;
	return true;
}

int main(){
	int nodes,edges;
	cin>>nodes;
	vector<Edge> graph[nodes];
	cin>>edges;
	for(int i=0;i<edges;i++){
		int v1,v2,wt;
		cin>>v1>>v2>>wt;
		graph[v1].push_back(Edge(v1,v2,wt));
		graph[v2].push_back(Edge(v2,v1,wt));
	}
	
	if(isConnected(graph,nodes)) cout<<"true\n";
	else cout<<"false\n";
	
	return 0;
}
