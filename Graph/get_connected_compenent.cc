#include<bits/stdc++.h>
using namespace std;
class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};

void solve(vector<Edge>graph[], int src, vector<int>& ans, bool vis[]){
	
	if(vis[src]) return;
	vis[src] = true;
	ans.push_back(src);
	for(Edge e:graph[src]){
		int nei = e.nbr;
		solve(graph,nei,ans,vis);
	}	
}

void getConnectedComponent(vector<Edge>graph[], int nodes, vector<vector<int>>& comps){
	bool vis[nodes] = {false};
	for(int i=0;i<nodes;i++){
		if(!vis[i]){
			vector<int> ans;
			solve(graph,i,ans,vis);
			if(ans.size() > 0) comps.push_back(ans);
		} 
	}
}

int main() {
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }


  vector<vector<int>> comps;
  getConnectedComponent(graph,vtces,comps);


  cout << "[";
  for (int i = 0 ; i < comps.size() ; i++) {
    cout << "[";
    for (int j = 0 ; j < comps[i].size() ; j++) {
      if (j != comps[i].size() - 1)
        cout << comps[i][j] << ", ";
      else
        cout << comps[i][j];

    }
    cout << "]";
    if (i != comps.size() - 1)cout << ", ";
  }
  cout << "]\n";
}
