#include<bits/stdc++.h>
using namespace std;

bool canWalkOff(int row, int col, vector<vector<int>>& arr){
	if(row < 0 || row >= arr.size() || col < 0 || col >= arr[0].size()) return true;
	return false;
}

void visitLand(int i, int j, vector<vector<int>>& arr, vector<vector<bool>>& vis, int& land){
	if(canWalkOff(i,j,arr)){
		land = 0;
		return;
	}
			
	if(vis[i][j] || !arr[i][j]) return;

	vis[i][j] = true;	
	land += 1;
	
	visitLand(i,j-1,arr,vis,land);
	visitLand(i-1,j,arr,vis,land);
	visitLand(i,j+1,arr,vis,land);
	visitLand(i+1,j,arr,vis,land);
}

int numEnclaves(vector<vector<int>>& arr){
	int n = arr.size(), m = arr[0].size();
	vector<vector<bool>> vis(n, vector<bool>(m,false));
	
	int total_land = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!vis[i][j] && arr[i][j]){
				int land_cells = 0;
				visitLand(i,j,arr,vis,land_cells);
				total_land += land_cells;
			}
		}
	}
	
	return total_land;
}

int main(){
	int m,n;
    cin>>m>>n;    
    vector<vector<int>> arr(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    }
    
    cout << numEnclaves(arr) << "\n";

	return 0;
}
