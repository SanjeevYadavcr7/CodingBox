#include "utils.h"

/* Approach: Directly pushing edges in priority queue to get least weighted edge  */

int getParent(int node, vector<int>& par){
	if(node == par[node]) return node;
	return par[node] = getParent(par[node],par);
}

int minCostConnectPoints(vector<vector<int>>& points) {
	int e = 0;
	int min_cost = 0;
	int n = points.size();
	vector<int> par(n);
	priority_queue<vector<int>, vector<vector<int>>, greater<>> edges;
	
	iota(par.begin(), par.end(), 0);
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			int u = i, v = j;
			int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			edges.push({w,u,v});
		}
	}
	
	while(e != n-1){
		auto edge = Q.front();
		Q.pop();
		
		int w = edge[0], u = edge[1], v = edge[2];
		u = getParent(u,par);
		v = getParent(v,par);
		if(u != v){
			min_cost += w;
			par[u] = v;
			edges++;
		}
	}
	return min_cost;
}





/*  Approach: Constructing Graph + Sorting Edges

bool sortByWeight(vector<int>& edge1, vector<int>& edge2){
	return edge1[0] < edge2[0];
}

void makeSet(vector<int>& par, int n){
	for(int i=0; i<n; i++) par[i] = i;
}

int getParent(int node, vector<int>& par){
	if(node == par[node]) return node;
	return par[node] = getParent(par[node],par);
}

void joinEdge(int u, int v, vector<int>& par, vector<int>& rank){
	if(rank[u] < rank[v]) par[u] = v;
	else if(rank[u] > rank[v]) par[v] = u;
	else{
		par[v] = u;
		rank[u]++;
	}
}

int getMinCost(vector<vector<int>>& edges, int n){
	int min_cost = 0;
	int e = edges.size();
	vector<int> par(n), rank(n);
	
	makeSet(par,n);
	
	for(int i=0; i<e; i++){
		vector<int> edge = edges[i];
		int u = edge[1], v = edge[2], w = edge[0];
		u = getParent(u,par);
		v = getParent(v,par);
		if(u != v){
			min_cost += w;
			joinEdge(u,v,par,rank);
		}
	}
	return min_cost;
}

int minCostConnectPoints(vector<vector<int>>& points) {
	int n = points.size();
	int cost = 0;
	vector<vector<int>> edges;
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			int u = i, v = j;
			int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
			edges.push_back({w,u,v});
		}
	}
	
	sort(edges.begin(),edges.end(),sortByWeight);
	cost = getMinCost(edges,n);
	return cost;
}
*/

int main() {
	int n;
	cin >> n;
	vector<vector<int>> points(n,vector<int>(2));
	for(int i=0; i<n; i++) cin >> points[i][0] >> points[i][1];
	
	int min_cost = minCostConnectPoints(points);
	cout << min_cost << endl;

	return 0;
}
