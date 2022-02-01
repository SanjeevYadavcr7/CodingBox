#include<bits/stdc++.h>
using namespace std;

bool hasCrossedBoundary(int row, int col, vector<vector<int>>& arr){
	if(row<0 || row==arr.size() || col<0 || col==arr[0].size()) return true;
	return false;
}

bool visitIslands(int i, int j, vector<vector<int>>& arr, vector<vector<bool>>& vis, string& dir){
	if(hasCrossedBoundary(i,j,arr) || vis[i][j] || !arr[i][j]) return false;
	
	vis[i][j] = true;
	if(visitIslands(i,j-1,arr,vis,dir)) dir += "l";
	if(visitIslands(i-1,j,arr,vis,dir)) dir += "t";
	if(visitIslands(i,j+1,arr,vis,dir)) dir += "r";
	if(visitIslands(i+1,j,arr,vis,dir)) dir += "d";
	
	return true;
}	

int getDistinctIslands(vector<vector<int>>& arr){
	int n = arr.size(), m = arr[0].size();
	vector<vector<bool>> vis(n, vector<bool>(m,false));
	unordered_map<string,bool> mp;
	int islands = 0;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!vis[i][j] && arr[i][j]){
				string psf = "";
				visitIslands(i,j,arr,vis,psf);
				if(!mp[psf]){
					islands++;
					mp[psf] = true;
				}
			}
		}
	}
	
	return islands;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> arr(n,vector<int>(m,0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> arr[i][j];
	}	

	int distinct_islands = getDistinctIslands(arr);
	cout << distinct_islands << "\n";
	
	return 0;
}
