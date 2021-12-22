#include<bits/stdc++.h>
using namespace std;

class Edge{
	public: 
		int src, nbr, wt;
		Edge(int src, int nbr, int wt){
			this->src = src;
			this->nbr = nbr;
			this->wt = wt;
		}
};

struct myComp {
	bool operator()( pair<int, string>& a, pair<int, string>& b){
    	return a.first > b.first;
  	}
};

string spath;
int spathwt = INT_MAX;

string lpath;
int lpathwt = INT_MIN;

string cpath;
int cpathwt = INT_MAX;

string fpath;
int fpathwt = INT_MIN;

priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;


void multisolver(vector<Edge> graph[], int src, int dest, bool vis[], int criteria, int k, string psf, int wsf) {
	if(src == dest){
		if(wsf > lpathwt){
			lpathwt = wsf;
			lpath = psf;
		}
		if(wsf < spathwt){
			spathwt = wsf;	
			spath = psf;
		}
		
		if(wsf > criteria){
			if(wsf < cpathwt){
				cpathwt = wsf;
				cpath = psf;
			}
		}
		if(wsf < criteria){
			if(wsf > fpathwt){
				fpathwt = wsf;
				fpath = psf;
			}
		}	
		
		if(pq.size() < k) pq.push({wsf,psf});
		else{
			if(pq.top().first < wsf){
				pq.pop();
				pq.push({wsf,psf});
			}
		}
	}
	
	vis[src] = true;
	for(Edge e : graph[src]){
		int nei = e.nbr;
		int wt = e.wt;
		if(!vis[nei]) multisolver(graph,nei,dest,vis,criteria,k,psf+to_string(nei),wsf+wt);
	}
	vis[src] = false;
}

int main(){
	int nodes,edges;
	cin>>nodes;
	vector<Edge> graph[nodes];
	cin>>edges;
	for(int i=0;i<edges;i++){
		int v1, v2, wt;
		cin>>v1>>v2>>wt;
		graph[v1].push_back(Edge(v1,v2,wt));
		graph[v2].push_back(Edge(v2,v1,wt));
	}
	
	int src,dest;
	cin >> src >> dest;

	int criteria;
	cin >> criteria;
	int k;
	cin >> k;	
	
	bool vis[nodes] = {false};
	
	multisolver(graph, src, dest, vis, criteria, k, src + "0", 0);
	cout << "Smallest Path = " << spath << "@" << spathwt << endl;
    cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
	cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
    cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt << endl;
	cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;

	return 0;
}
