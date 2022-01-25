#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>& arr){
	cout << "\n";
	for(auto i : arr){
		for(int j : i) cout << j << " ";
		cout << "\n"; 
	}
}

bool isValidOption(vector<vector<int>>& arr,int i,int j,int val){
	for(int x=0; x<arr.size(); x++){
		if(arr[x][j] == val) return false;
	}
	
	for(int y=0; y<arr[0].size(); y++){
		if(arr[i][y] == val) return false;
	}
	
	int smi = 3 * ( i / 3 );
	int smj = 3 * ( j / 3 );
	for(int x=0; x<3; x++){
		for(int y=0; y<3; y++){
			if(arr[smi+x][smj+y] == val) return false;
		}
	}
	return true;
}

void solveSudoku(vector<vector<int>>& arr, int i, int j){
	if(i == arr.size()){
		display(arr);
		return;
	}
	
	int ni = 0, nj = 0;
	if(j == arr[0].size()-1){
		ni = i+1, nj = 0;
	}	
	else{
		ni = i;
		nj = j+1;
	}
	
	if(arr[i][j] != 0) solveSudoku(arr,ni,nj);
	else{
		for(int po=1; po<=arr.size(); po++){
			if(isValidOption(arr,i,j,po)){
				arr[i][j] = po;
				solveSudoku(arr,ni,nj);
				arr[i][j] = 0;
			}
		}
	}
}


int main(){
	int n = 9;
	vector<vector<int>> arr(n, vector<int>(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) cin >> arr[i][j];
	
	solveSudoku(arr,0,0);

	return 0;
}
