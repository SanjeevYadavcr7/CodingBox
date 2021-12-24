#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge{
	public:
	  int src = 0;
	  int nbr = 0;
	  Edge(int src, int nbr){
		this->src = src;
		this->nbr = nbr;
	  }
};

bool isBipartite(vector<vector<Edge>>& graph, int src, bool vis[]){
	int cycle_size = 0;
	queue<int> q;
	q.push(src);
	
	while(!q.empty()){
		int curr_node = q.front();
		q.pop();
		
		if(vis[curr_node]){
			//cout<<"Cycle Size = "<<cycle_size<<endl;
			if(cycle_size & 1) return false;
			else cycle_size = 0;
			continue;
		}
		vis[curr_node] = true;
		cycle_size++;
		for(Edge e:graph[curr_node]){
			int nei = e.nbr;
			if(!vis[nei]) q.push(nei);
		}
	}
	return true;
}

int main() {
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
  }
  
  bool vis[vtces] = {false}, is_bipartite = true;
  for(int curr_node=0; curr_node < vtces; curr_node++){
  	if(!isBipartite(graph,curr_node,vis)){
  		is_bipartite = false;
  		break;
  	} 
  }
  if(is_bipartite) cout<<"true\n";
  else cout<<"false\n";
  
  return 0;
}























