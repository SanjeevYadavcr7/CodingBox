#include<bits/stdc++.h>
using namespace std;

class Edge{
	public: 
		int src;
		int nbr;
		int wt;
		
		Edge(){
			src = nbr = wt = 0;
		}
		
		Edge(int src, int nbr, int wt){
			this->src = src;
			this->nbr = nbr;
			this->wt = wt;
		}
};

void printAllPaths(vector<Edge> graph[], int src, int dest, bool vis[], string path, vector<string>& ans){
	if(src == dest){
		path += to_string(src);
		ans.push_back(path);
		return;
	}
	vis[src] = true;
	path += to_string(src);
	for(Edge e:graph[src]){
		int nei = e.nbr;
		if(!vis[nei]){
			printAllPaths(graph,nei,dest,vis,path,ans);		
		}
	}
	vis[src] = false;
}

int main(){
	int v,e;
	cin>>v;
	vector<Edge> graph[v];
	
	cin>>e;
	for(int i=0;i<e;i++){
		int v1,v2,wt;
		cin>>v1>>v2>>wt;
		graph[v1].push_back(Edge(v1,v2,wt));
		graph[v2].push_back(Edge(v2,v1,wt));
	}
	
	int src,dest;
	cin>>src>>dest;
	
	bool vis[v] = {false};
	vector<string> path;
	printAllPaths(graph,src,dest,vis,"",path);
	
	for(string p:path) cout<<p<<endl;
	
	return 0;
}
