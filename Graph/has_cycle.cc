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

bool hasCycle(vector<vector<Edge>> graph, int src){
	int n = graph.size();
	bool vis[n] = {false};
	
	queue<int> q;
	q.push(src);
	
	while(!q.empty()){
		int curr_node = q.front();
		q.pop();
				
		if(vis[curr_node]) return true;

		vis[curr_node] = true;	
		for(Edge e:graph[curr_node]){
			int nei = e.nbr;
			if(!vis[nei]) q.push(nei);	
		}
	}
	return false;
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
  
  cout<<endl;
  int src = 0;
  if(hasCycle(graph,src)) cout<<"true";
  else cout<<"false";
  cout<<endl;
  
  return 0;
}

