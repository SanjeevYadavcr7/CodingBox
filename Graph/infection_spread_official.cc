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

int getInfectedPeople(vector<vector<Edge>>& graph, int total_nodes, int src, int t){
	bool vis[total_nodes] = {false};
	queue<pair<int,int>> q;
	q.push({src,1});
	
	int infected = 0;
	while(!q.empty()){
		int curr_node = q.front().first;
		int curr_time = q.front().second;
		q.pop();
		
		if(vis[curr_node]) continue;
		vis[curr_node] = true;
		if(curr_time <= t) infected++;
		for(Edge e:graph[curr_node]){
			int nei = e.nbr;
			int new_time = curr_time+1;
			if(!vis[nei]) q.push({nei,new_time});
		}
	}	
	return infected;
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
  
  int src,t;
  cin>>src>>t;
  
  int patients = getInfectedPeople(graph,vtces,src,t);
  cout<<patients<<endl;
  
  return 0;
}

