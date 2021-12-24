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

void bfs(vector<vector<Edge>> graph, int src){
	int n = graph.size();
	bool vis[n] = {false};
	
	queue<pair<int,string>> q;
	q.push({src,to_string(src)});
	
	while(!q.empty()){
		int curr_node = q.front().first;
		string path = q.front().second;
		q.pop();
		
		if(!vis[curr_node]){
			vis[curr_node] = true;
			cout<<curr_node<<"@"<<path<<"\n";
			
			for(Edge e:graph[curr_node]){
				int nei = e.nbr;
				if(!vis[nei]){
					string new_path = path+to_string(nei);
					q.push({nei,new_path});	
				}
			}
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
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
  }

  int src;
  cin >> src;
  
  bfs(graph,src);

  return 0;
}
