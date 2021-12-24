#include <bits/stdc++.h>
using namespace std;
typedef pair< int, pair< int, string> > pip;

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

void getShortestPathToAllCities(vector<vector<Edge>>& graph, int src){
	int total_cities = graph.size();
	bool vis[total_cities] = {false};
	priority_queue<pip, vector<pip>, greater<pip>> pq;
	pq.push({0,{src,to_string(src)}});
	
	while(!pq.empty()){
		auto it = pq.top();
		pq.pop();
		int curr_city = it.second.first;
		if(vis[curr_city]) continue;
		
		vis[curr_city] = true;
		int min_cost = it.first;
		string path = it.second.second;
		cout<<curr_city<<" via "<<path<<" @ "<<min_cost<<"\n";
		for(Edge e:graph[curr_city]){
			int nei = e.nbr;
			int new_cost = min_cost+e.wt;
			string new_path = path+to_string(nei);
			if(!vis[nei]) pq.push({new_cost,{nei,new_path}});
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
  cin>>src;
  
  getShortestPathToAllCities(graph,src);
  
  return 0;
}

