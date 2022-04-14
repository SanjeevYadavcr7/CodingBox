/*
	Approach: BFS
	TC: O(M*N) | SC: O(M*N)
	
	example: 
	m = 10 n = 8

	Grid[][] = 
	1 1 1 1 1 1 1 1
	1 0 1 1 1 0 1 1 
	1 1 1 1 0 1 1 1
	1 1 1 1 1 1 1 1
	1 1 1 0 1 1 0 1
	1 1 1 1 1 1 1 1
	1 1 1 1 1 1 0 1
	1 1 0 1 1 0 1 1
	1 1 1 1 1 1 1 1
	1 1 1 1 0 1 1 1

	start_x = 9, start_y = 3
	Total Travels by Bob = 32 - 1 = 31
	
	NOTE: subtracting 1 to remove the initial block from where Bob started his journey.
*/


#include<bits/stdc++.h>
using namespace std;

bool isOutOfGrid(int row, int col, vector<vector<int>>& grid){
	if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return true;
	return false;
}

int getTotalTraveledBlocks(vector<vector<int>>& grid, int start_x, int start_y){
	int bob_travel = 0;
	int m = grid.size(), n = grid[0].size();
	queue<pair<int,int>> Q;
	vector<vector<int>> directions = {{-1,-1}, {1,-1}, {1,1}, {-1,1}};
	
	Q.push({start_x,start_y});
	while(!Q.empty()){
		int size = Q.size();
		while(size--){
			auto loc = Q.front();
			Q.pop();
			
			int x = loc.first, y = loc.second;
			if(grid[x][y] == 0) continue;
			
			if(grid[x][y] == 1){
				bob_travel++;
				grid[x][y] = 0;
				for(auto moves : directions){
					int new_x = x + moves[0];
					int new_y = y + moves[1];
					if(isOutOfGrid(new_x,new_y,grid) || grid[new_x][new_y] == 0) continue;
					Q.push({new_x,new_y});
				}
			}
		}		
	}
	return bob_travel-1;
}

int main(){
	int m,n;
	int x,y;
	cin >> m >> n;
	vector<vector<int>> grid(m,vector<int>(n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) cin >> grid[i][j];
	cin >> x >> y;
	
	int travelled_blocks = getTotalTraveledBlocks(grid,x,y);
	cout << travelled_blocks << "\n"; 
	
	return 0;
}

