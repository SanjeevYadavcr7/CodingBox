#include <bits/stdc++.h>
using namespace std;
typedef pair< int, pair< int, int> > pip;

class Edge{
	public:
	  int src = 0;
	  int nbr = 0;
	  Edge(int src, int nbr){
		this->src = src;
		this->nbr = nbr;
	  }
};

void tological_travel(vector<vector<Edge>>& graph, stack<int>& order, bool vis[], int src){
	
	vis[src] = true;
	for(Edge e:graph[src]){
		int nei = e.nbr;
		if(!vis[nei]) tological_travel(graph,order,vis,nei);
	}	
	order.push(src);
}

void topological_sort(vector<vector<Edge>>& graph){
	stack<int> order;
	int nodes = graph.size();
	bool vis[nodes] = {false};
	for(int curr_node = 0; curr_node < nodes; curr_node++){
		if(!vis[curr_node]) tological_travel(graph,order,vis,curr_node);
	}
	
	while(!order.empty()){
		cout<<order.top()<<"\n";
		order.pop();
	}
}

int main() {
  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
  }

  topological_sort(graph);  
   
  return 0;
}

