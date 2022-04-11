#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>& grid);

/* 	Type: Optimal
	Considering 2D to be flattened 
	TC: O(M*N) | SC: O(1) 
*/

void reverseGrid(int beg, int end, vector<vector<int>>& grid){
	int m = grid.size(), n = grid[0].size();
	
	while(beg < end){
		int beg_row = beg/n, beg_col = beg%n;
		int end_row = end/n, end_col = end%n;
		if(end_row == m) end_row = 0;
		swap(grid[beg_row][beg_col], grid[end_row][end_col]);
		beg++, end--;
	}
}

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
	int m = grid.size(), n = grid[0].size();
	int len = m*n-1;
	
	k %= (m*n);
	if(k > 0){
		reverseGrid(0,len,grid);
		reverseGrid(0,k-1,grid);
		reverseGrid(k,len,grid);	
	}
	return grid; 
}


/* 
	Type: Sub-optimal
	TC: O(m*n*k)  |  SC: O(1)

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
	int m = grid.size(), n = grid[0].size();
	int val_to_be_placed;
	int i, j;
	
	k %= (m*n);	
		
	while(k--){
		i = 0, j = 0;
		val_to_be_placed = grid[m-1][n-1];
		while(i<m){
			if(j == n){
				i++;
				if(i == m) break;
				j = 0;
			}
			int curr_val = grid[i][j];
			grid[i][j] = val_to_be_placed;
			val_to_be_placed = curr_val;
			j++;
		}
	}	
	return grid;
}
*/

int main(){
	int m,n;
	int k;
	cin >> m >> n >> k;
	vector<vector<int>> grid(m,vector<int>(n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin >> grid[i][j];
	
	vector<vector<int>> res = shiftGrid(grid,k);
	display(grid);

	return 0;
}


/* Display() ---------------------------------------------*/

void display(vector<vector<int>>& grid){
	cout << "\n";
	for(auto i:grid){
		for(int j:i) cout << j << " ";
		
	}
	cout << "\n";
}
