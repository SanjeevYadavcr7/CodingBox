#include<bits/stdc++.h>
using namespace std;

bool hasCrossedBoundary(int row, int col, vector<vector<int>>& arr){
	if(row < 0 || row >= arr.size() || col < 0 || col >= arr[0].size()) return true;
	return false;
}

void getEnclaves(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& land){
    if(hasCrossedBoundary(i,j,grid)){
    	land = INT_MIN;
    	return;
    };
    
    if(vis[i][j] || !grid[i][j]) return;
  
    vis[i][j] = true;
    land += 1;
    getEnclaves(i,j-1,grid,vis,land);
    getEnclaves(i-1,j,grid,vis,land);
   	getEnclaves(i,j+1,grid,vis,land);
    getEnclaves(i+1,j,grid,vis,land);
}

int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]){
                	int no_of_enclaves = 0;
                	getEnclaves(i,j,grid,vis,no_of_enclaves);
                	if(no_of_enclaves > 0)ans += no_of_enclaves;
            		//cout << i << "," << j << " | " << no_of_enclaves << "\n";
                }       
            }
        }
        return ans;
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
