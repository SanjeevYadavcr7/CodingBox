#include<bits/stdc++.h>

using namespace std;

class Edge {
public:
  int src = 0;
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt  = wt;
  }
};

void getHamiltonianPathHelper(vector<Edge> graph[],int beg, int src, bool vis[], int total_nodes, int cnt, string psf){

	if(vis[src]) return;

	if(cnt == total_nodes){
		cout<<psf;
		int is_cycle = 0;
		for(Edge e:graph[src]){
			int nei = e.nbr;
			if(nei == beg){
				is_cycle = 1;
				break;
			}
		}
		if(is_cycle) cout<<"*\n";
		else cout<<".\n";
		return;
	}
	
	vis[src] = true;
	for(Edge e:graph[src]){
		int nei = e.nbr;
		if(!vis[nei]){
			getHamiltonianPathHelper(graph,beg,nei,vis,total_nodes,cnt+1,psf+to_string(nei));
		}
	}	
	vis[src] = false;	
}

void getHamiltonianPath(vector<Edge> graph[], int src, int nodes){
	bool vis[nodes] = {false};
	getHamiltonianPathHelper(graph,src,src,vis,nodes,1,to_string(src));
}	

int main() {
  int vtces;
  cin >> vtces;
  vector<Edge> graph[vtces];


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  }
  int src;
  cin >> src;

  getHamiltonianPath(graph,src,vtces);
	
  return 0;
}









