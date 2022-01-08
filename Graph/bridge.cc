#include<bits/stdc++.h>
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

int nodes,edges;

void countComponentsHelper(vector<Edge> graph[], int src, bool vis[]){
	if(vis[src]) return;
	vis[src] = true;
	for(Edge e:graph[src]){
		int nei = e.nbr;
		countComponentsHelper(graph,nei,vis);
	}
}

int countComponents(vector<Edge> graph[]){
	bool vis[nodes] = {false};
	int cnt = 0;
	for(int curr_node = 0;curr_node < nodes;curr_node++){
		if(!vis[curr_node]){
			cnt++;
			countComponentsHelper(graph,curr_node,vis);
		}
	}
	return cnt;
}

void removeEdge(vector<Edge> graph[], int n1, int n2){
	int cnt = -1;
	for(Edge e:graph[n1]){
		int nei = e.nbr;
		cnt++;
		if(nei == n2) break;
	}
	graph[n1][cnt].nbr = n1;
	
	cnt = -1;
	for(Edge e:graph[n2]){
		int nei = e.nbr;
		cnt++;
		if(nei == n1) break;
	}
	graph[n2][cnt].nbr = n2;
}

int isBridge(vector<Edge> graph[], int n1, int n2){
	int prev_compos = countComponents(graph);
	removeEdge(graph,n1,n2);
	int after_compos = countComponents(graph);
	int compos_diff = after_compos - prev_compos;
	if(compos_diff == 0) return false;
	return true;	
}


int main(){	
	cin>>nodes;
	vector<Edge> graph[nodes];
	cin>>edges;
	for(int i=0;i<edges;i++){
		int v1,v2;
		cin>>v1>>v2;
		graph[v1].push_back(Edge(v1,v2));
		graph[v2].push_back(Edge(v2,v1));
	}
	
	int n1,n2;
	cin>>n1>>n2;
	if(isBridge(graph,n1,n2)) cout<<"true\n";
	else cout<<"false\n";
	
	return 0;
}
