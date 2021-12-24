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

void iterativeDFS(vector<vector<Edge>>& graph, int src){
	int nodes = graph.size();
	bool vis[nodes] = {false};
	stack<pair<int,string>> stk;
	stk.push({src,to_string(src)});
	
	while(!stk.empty()){
		auto it = stk.top();
		stk.pop();
		int curr_node = it.first;
		
		if(vis[curr_node]) continue;
		vis[curr_node] = true;
		string path = it.second;
		cout<<curr_node<<"@"<<path<<"\n";
		for(Edge e:graph[curr_node]){
			int nei = e.nbr;
			if(!vis[nei]){
				string new_path = path+to_string(nei);
				stk.push({nei,new_path});
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
    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));
  }
  
  int src;
  cin>>src;
  iterativeDFS(graph,src);  
	  
  return 0;
}

