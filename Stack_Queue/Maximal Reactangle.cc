#include<bits/stdc++.h>
using namespace std;

int getCurrRowArea(vector<int>& heights){
	stack<int> stk;
	int n = heights.size();
	int max_area = 0;
	
	for(int i=0; i<n; i++){
		if(stk.empty() || heights[i] >= heights[stk.top()]) stk.push(i);
		else{
			int height = heights[stk.top()];
			stk.pop();
			
			int area = height * (stk.empty() ? i : i - stk.top()-1);
			max_area = max(max_area,area);
			i--;
		}
	}
	
	while(!stk.empty()){
		int height = heights[stk.top()];
		stk.pop();
		
		int area = height * (stk.empty() ? n : n-stk.top()-1);
		max_area = max(max_area,area);
	}
	
	return max_area;
}

void display(vector<vector<int>>& arr){
	cout << "\n";
	for(auto i : arr){
		for(int j : i) cout << j << " ";
		cout << "\n"; 
	}
}

int maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	int max_area = 0;
	vector<vector<int>> grid(m,vector<int>(n,0));
	
	
	for(int j=0; j<n; j++) grid[0][j] = matrix[0][j] - '0';
	
	for(int i=1; i<m; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j] == '1') grid[i][j] = grid[i-1][j] + 1;
		}
	}
	
	for(auto row : grid){
		int area = getCurrRowArea(row);
		max_area = max(max_area,area);
	}
	return max_area;
}

int main(){
	int m,n;
	cin >> m >> n;
	vector<vector<char>> matrix(m,vector<char>(n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) cin >> matrix[i][j];
		
	int area = maximalRectangle(matrix);
	cout << area << "\n";
	
	return 0;
}
