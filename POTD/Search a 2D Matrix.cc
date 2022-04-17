#include<bits/stdc++.h>
using namespace std;

int binarySearch(int target, vector<vector<int>>& matrix){
	int m = matrix.size();
	int n = matrix[0].size();
	int l = 0, r = m-1; 
	
	while(l<=r){
		int row = (r-l)/2+l;
		if(matrix[row][0] <= target && matrix[row][n-1] >= target) return row;
		else if(matrix[row][n-1] < target) l = row+1;
		else r = row-1;
	}
	return -1;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	
	int row = binarySearch(target,matrix); 
	if(row == -1) return false;
	
	int l = 0, r = n-1;
	while(l<=r){
		int col = (r-l)/2+l;
		if(matrix[row][col] == target) return true;
		else if(matrix[row][col] < target) l = col+1;
		else r = col-1;
	}
	return false;
}

int main(){
	int m,n;
	int target;
	cin >> m >> n;
	vector<vector<int>> matrix(m,vector<int>(n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) cin >> matrix[i][j];
	cin >> target;
	
	if(searchMatrix(matrix,target)) cout << "true\n";
	else cout << "false\n";
		
	return 0;
}
