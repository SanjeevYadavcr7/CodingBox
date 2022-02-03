#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

void visitIstands(int row, int col, int n, vector<vector<int>>& grid, set<pi>& island){
	if(row < 0 || row == n || col < 0 || col == n || !grid[row][col]) return;
	
	grid[row][col] = 0;
	island.insert({row,col});
	
	visitIstands(row,col-1,n,grid,island);
	visitIstands(row-1,col,n,grid,island);
	visitIstands(row,col+1,n,grid,island);
	visitIstands(row+1,col,n,grid,island);
}

int shortestBridge(vector<vector<int>>& grid){
	int n = grid.size();
	//vector<vector<bool>> vis(n,vector<bool>(n,false));
	set<pi> island1, island2;
	
	bool visting_first_island = true;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grid[i][j] == 1){
				if(visting_first_island){
					visitIstands(i,j,n,grid,island1);
					visting_first_island = false;
				} 
				else visitIstands(i,j,n,grid,island2);
			}
		}
	}
	
	int min_flips = INT_MAX;
	for(auto i : island1)
		for(auto j : island2)
			min_flips = min( min_flips, (abs(i.first - j.first) + abs(i.second - j.second)-1) );
	
	return min_flips;	
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v1(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>v1[i][j];
    }
    cout<<shortestBridge(v1);
    
    return 0;
}
