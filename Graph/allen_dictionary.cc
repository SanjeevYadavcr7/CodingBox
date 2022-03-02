#include<bits/stdc++.h>
using namespace std;

void doTopologicalSort(char src, vector<char> graph[], unordered_map<char,bool>& vis, stack<char>& stk){
	if(vis[src]) return;
	
	vis[src] = true;
	for(char node : graph[src])
		doTopologicalSort(node,graph,vis,stk);
	
	stk.push(src);
}

string topoLogicalSort(vector<char> graph[], unordered_set<char>& nodes){
	stack<char> stk;
	
	unordered_map<char,bool> vis;
	for(char node : nodes) vis[node] = false;
	
	for(char src : nodes){
		doTopologicalSort(src,graph,vis,stk);
	}
	
	string order = "";
	while(!stk.empty()){
		order += stk.top();
		stk.pop();
	}
	return order;
}

void dfs(int src, vector<vector<int>>& graph, vector<int>& vis, string& ans){
	vis[src] = 1;
	for(int nei : graph[src]){
		if(!vis[nei]) dfs(nei,graph,vis,ans);
	} 
	char ch = src + 'a';
	ans = ch + ans;
}

string alienOrder(vector<string>& words) {
	int K = 0, n = words.size();
	for(string word : words){
		for(char ch : word) K = max(K,ch-'a');
	}
	
	vector<vector<int>> graph(K+1);
	for(int i=0; i<n-1; i++){
		string curr = words[i];
		string next = words[i+1];
		for(int j=0; j<min(curr.size(),next.size()); j++){
			if(curr[j] != next[j]){
				graph[curr[i]-'a'].push_back(next[j]-'a');
				break;
			}
		}
	}
	
	vector<int> vis(K,0);
	string ans = "";
	for(int i=0; i<K; i++){
		if(!vis[i]) dfs(i,graph,vis,ans);
	}
	return ans;
}

int main() { 
 	int n;
 	cin>>n;
 	vector<string> words(n);
 	for(int i = 0; i < n; i++) cin>>words[i];
     
    cout<<alienOrder(words)<<endl;
	
	return 0;
}
