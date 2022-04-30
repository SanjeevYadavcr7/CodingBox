#include<iostream>
#include<vector>
using namespace std;

struct Node {
	string key;
	double val;
	Node(string _key, double _val){
		key = _key;
		val = _val;
	}
};

unordered_map<string,vector<Node*>> buildGraph(vector<vector<string>>& equations, vector<double>& values){
	int n = values.size();
	unordered_map<string,vector<Node*>> G;
	
	for(int i=0; i<n; i++){
		string u = equations[i][0], v = equations[i][1];
		double val = values[i];
		G[u].push_back(new Node(v,val));
		G[v].push_back(new Node(u,1/val));
	}
	return G;
}

double findDis(string node, string tar, unordered_map<string,bool>& vis, unordered_map<string,vector<Node*>>& G) {
	if(G.find(node) == G.end() || G.find(tar) == G.end()) return -1.0;
	if(node == tar) return 1.0;
	
	vis[node] = true;
	for(Node* nei : G[node]){
		if(!vis[nei->key]){
			double ans = findDis(nei->key,tar,vis,G);
			if(ans != -1.0) return ans * nei->val;
		}
	}
	return -1;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	int q = queries.size();
	vector<double> res(q);
	unordered_map<string,vector<Node*>> G = buildGraph(equations,values);
	
	for(int i=0; i<q; i++){
		unordered_map<string,bool> vis;
		res[i] = findDis(queries[i][0],queries[i][1],vis,G);
	}
	return res;
}

int main() {
	int n,q;
	cin >> n;
	vector<double> values(n);
	vector<<vector<string>> queries(q);
	vector<vector<string>> equations(n,vector<string>(2));
	
	for(int i=0; i<n; i++) cin >> equations[i][0] >> equations[i][1];
	for(int i=0; i<n; i++) cin >> values[i];
	
	while(q--) {
		string x,y;
		cin >> x >> y;
	}

	return 0;
}
