#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

class Edge{
    public:
    int v;
    int wt;
    Edge(int v,int wt)
    {
        this->v=v;
        this->wt=wt;
    }
};

int getMinCost(vector<vector<Edge>>& graph){
	int n = graph.size();
	vector<bool> vis(n);
	priority_queue<pi,vector<pi>,greater<pi>> Q;
	
	int min_cost = 0;
	Q.push({0,0});
	while(!Q.empty()){
		auto it = Q.top();
		int cost = it.first;
		int node = it.second;
		Q.pop();
		
		if(vis[node]) continue;
		vis[node] = true;
		min_cost += cost;
		for(Edge e : graph[node]){
			int nei = e.v, temp_cost = e.wt;
			Q.push({temp_cost,nei});
		}
	}
	return min_cost;
}


int main()
{
    int vtces;
    cin>>vtces;
    vector<vector<Edge>> graph(vtces);
    int edges;cin>>edges;
    for(int i=0;i<edges;++i){
        int v1,v2,wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v2,wt));
        graph[v2].push_back(Edge(v1,wt));
    }
    
	int min_cost = getMinCost(graph);
    cout << min_cost << "\n";
    
    return 0;
}
