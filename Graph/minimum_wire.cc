#include <bits/stdc++.h>
using namespace std;
typedef pair< int, pair< int, int> > pip;

class Edge{
	public:
	  int src = 0;
	  int nbr = 0;
	  int wt = 0;
	  Edge(int src, int nbr, int wt){
		this->src = src;
		this->nbr = nbr;
	  	this->wt = wt;
	  }
};

void getMinimumSpanningTree(vector<vector<Edge>>& graph, int src){
	int total_cities = graph.size();
	bool vis[total_cities] = {false};
	priority_queue<pip, vector<pip>, greater<pip>> pq;
	pq.push({0,{0,-1}});
	
	while(!pq.empty()){
		auto it = pq.top();
		pq.pop();
		int curr_node = it.second.first;
		if(vis[curr_node]) continue;
		
		vis[curr_node] = true;
		int cost = it.first;
		int from = it.second.second;
		if(from != -1) cout<<"["<<curr_node<<"-"<<from<<"@"<<cost<<"]\n";
		for(Edge e:graph[curr_node]){
			int nei = e.nbr;
			int new_cost = e.wt;
			if(!vis[nei]) pq.push({new_cost,{nei,curr_node}});
		}
	}
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
    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));
  }
  
  int src;
  src = -1;  
  getMinimumSpanningTree(graph,src);
  
  return 0;
}

