#include<bits/stdc++.h>
using namespace std;

bool isQueenSafe(vector<vector<int>> chess, int row, int col){
		
		// cheecking in vertical upwards direction
		for(int i=row, j=col;i>=0;i--){
			if(chess[i][j] == 1) return false;
		}
		
		// checking in left diagonal
		for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
			if(chess[i][j] == 1) return false;
		}
		
		// checking in right diagonal
		for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--,j++){
			if(chess[i][j] == 1) return false;
		}
		
		return true; // if safe
}

void printNQueens(vector<vector<int>> chess, string qsf, int row){
	
	if(row == chess.size()){
		cout<<qsf<<"."<<endl;
		return;
	}
	
	for(int col=0;col<chess[0].size();col++){
		if(isQueenSafe(chess, row, col)){
			chess[row][col] = 1;
			string ans = qsf+to_string(row)+"-"+to_string(col)+", ";
			printNQueens(chess, ans, row+1);
			chess[row][col] = 0;
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>chess(n, vector<int>(n));
	printNQueens(chess, "", 0);
	return 0;
}
