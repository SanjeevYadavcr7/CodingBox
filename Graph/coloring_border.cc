#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>& arr);

void markBoundary(vector<vector<int>>& arr, int row, int col, int val){
	if(row < 0 || row == arr.size() || col < 0 || col == arr[0].size()) return;
	
	int cnt = 0;
	arr[row][col] *= -1;
	if(col > 0 && abs(arr[row][col]) == abs(arr[row][col-1])){
		if(arr[row][col-1] == val) markBoundary(arr,row,col-1,val); 
		cnt++;
	}
	
	if(row > 0 && abs(arr[row][col]) == abs(arr[row-1][col])){
		if(arr[row-1][col] == val) markBoundary(arr,row-1,col,val);
		cnt++;
	}
	
	if(col+1 < arr[0].size() && abs(arr[row][col]) == abs(arr[row][col+1])){
		if(arr[row][col+1] == val) markBoundary(arr,row,col+1,val);
		cnt++;
	}
	
	if(row+1 < arr.size() && abs(arr[row][col]) == abs(arr[row+1][col])){
		if(arr[row+1][col] == val) markBoundary(arr,row+1,col,val);
		cnt++;
	}
	
	if(cnt == 4) arr[row][col] *= -1;
}

void colorBoundary(vector<vector<int>>& arr, int color){
	for(int i=0; i<arr.size(); i++){
		for(int j=0; j<arr[0].size(); j++) if(arr[i][j] < 0) arr[i][j] = color;
	}
}

void coloring_border(vector<vector<int>>& arr, int row, int col, int color, int cnt, int val){
	markBoundary(arr,row,col,arr[row][col]);
	colorBoundary(arr,color);
	display(arr);
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>>arr(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  }

  int row, col, color;
  cin >> row >> col >> color;
  
  int cnt = 1;
  coloring_border(arr,row,col,color,cnt,arr[row][col]);
  
  return 0;
}






















void display(vector<vector<int>>& arr){
	cout << "\n";
	for(auto i : arr){
		for(int j : i) cout << j << " ";
		cout << "\n";
	}
}
