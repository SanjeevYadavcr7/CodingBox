#include <bits/stdc++.h>
using namespace std;

void visitIslands(vector<vector<int>>& arr, int i, int j, vector<vector<bool>>& vis){
	if(i<0 || j<0 || i>=vis.size() || j>=vis[0].size() || arr[i][j] == 1 || vis[i][j]) return;
	
	vis[i][j] = true;
	visitIslands(arr,i-1,j,vis);
	visitIslands(arr,i+1,j,vis);
	visitIslands(arr,i,j+1,vis);
	visitIslands(arr,i,j-1,vis);
}

int getNoOfIslands(vector<vector<bool>>& vis, vector<vector<int>>& arr){
	int islands = 0;
	int n = arr.size(), m = arr[0].size();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] && arr[i][j] == 0){
				islands++;
				visitIslands(arr,i,j,vis);
			}
		}
	}
	return islands;
}

int main(){
 	int n, m;
 	cin >> n >> m;
	vector<vector<int>> arr;
 	for (int i = 0; i < n; i++){
    	vector<int> ans;
    	for (int j = 0; j < m; j++){
		  int res;
		  cin >> res;
		  ans.push_back(res);
		}
		arr.push_back(ans);
 	}
 	
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	int no_of_islands = getNoOfIslands(vis,arr);	
	cout<<no_of_islands<<endl;
	
	return 0;
}
