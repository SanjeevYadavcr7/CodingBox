#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>& matrix);

vector<vector<int>> generateMatrix(int n){
	int val = 1;
	int beg_row, end_row, beg_col, end_col;
	vector<vector<int>> matrix(n,vector<int>(n,0));
	
	beg_row = beg_col = 0;
	end_row = end_col = n-1;
	while( beg_row <= end_row && beg_col <= end_col ){
		for(int col=beg_col; col<=end_col; col++) matrix[beg_row][col] = val++;
		beg_row++;
		
		for(int row=beg_row; row<=end_row; row++) matrix[row][end_col] = val++;
		end_col--;
		
		for(int col=end_col; col>=beg_col; col--) matrix[end_row][col] = val++;
		end_row--;
		
		for(int row=end_row; row>=beg_row; row--) matrix[row][beg_col] = val++;
		beg_col++;
	}
	return matrix;
}

/*
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n,vector<int>(n,0));
	int m = n;
	int cnt = 1;
	int total_elements = n*n;
	int row = 0, col = 0;
	int i,j;
	while(true){
		i = row, j = col;
		while(j<n) matrix[i][j++] = cnt++;
		row++, j--;
		
		if(total_elements < cnt) break;
		
		i = row;
		while(i<m) matrix[i++][j] = cnt++;
		n--, i--;
		
		if(total_elements < cnt) break;
		
		j = n-1;
		while(j>=col) matrix[i][j--] = cnt++;
		m--, j++; 
		
		if(total_elements < cnt) break;
	
		i = m-1;
		while(i >= row)	matrix[i--][j] = cnt++;
		i++, col++;	
		
		if(total_elements < cnt) break;
	}
	return matrix;
}
*/

int main(){
	int n;
	cin >> n;
	vector<vector<int>> matrix = generateMatrix(n);
	display(matrix);

	return 0;
}






/*----------- Display() -------------------*/

void display(vector<vector<int>>& matrix){
	for(auto i : matrix){
		cout << "\n";
		for(int j : i) cout << j << " ";
	}
	cout << "\n";
}
