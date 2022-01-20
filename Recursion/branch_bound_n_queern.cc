#include<bits/stdc++.h>
using namespace std;

void placingQueens(int curr_row, vector<int> &cols, vector<int> &d1, vector<int> &d2, vector<vector<int>> &arr, int n, string path){
	
	if(curr_row == n){
		cout << path << " .\n";
		return;
	}
	
	for(int curr_col=0; curr_col<n; curr_col++){
		int i1 = curr_row + curr_col;
		int i2 = curr_row - curr_col + (n-1);
		if(!cols[curr_col] && !d1[i1] && !d2[i2]){
			cols[curr_col] = d1[i1] = d2[i2] = 1;
			string new_path = path + to_string(curr_row) + "-" + to_string(curr_col) + ", ";
			placingQueens(curr_row+1,cols,d1,d2,arr,n,new_path);	
			cols[curr_col] = d1[i1] = d2[i2] = 0;
		}
	}
}

void placeQueens(vector<vector<int>> &arr, int n){
	int d = 2*n-1;
	vector<int> cols(n,0);
	vector<int> d1(d,0), d2(d,0);	
	
	placingQueens(0,cols,d1,d2,arr,n,"");
}

int main(){
	int n;
	cin >> n;
	
	vector<vector<int>> arr(n,vector<int>(n,0));
	placeQueens(arr,n);

	return 0;
}
