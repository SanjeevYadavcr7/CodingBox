#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
	if(i<0 || j<0 || i >= n || j >= m || grid[i][j] != 1) return;
	
	grid[i][j] = 2;
	dfs(i-1,j,n,m,grid);
	dfs(i+1,j,n,m,grid);
	dfs(i,j-1,n,m,grid);
	dfs(i,j+1,n,m,grid);
}

int numEnclaves(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	
	for(int i=0; i<n; i++){
		if(grid[i][0] == 1){
			
			dfs(i,0,n,m,grid);
		} 
		if(grid[i][m-1] == 1) dfs(i,m-1,n,m,grid);
	}  
	for(int j=0; j<m; j++){
		if(grid[0][j] == 1) dfs(0,j,n,m,grid);
		if(grid[n-1][j] == 1) dfs(n-1,j,n,m,grid);
	}      
	
	int no_of_enclaves = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(grid[i][j] == 1) no_of_enclaves++;
			 	
	return no_of_enclaves;
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
