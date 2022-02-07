#include<bits/stdc++.h>
using namespace std;

bool isOutsideBoard(int row, int col, vector<vector<int>>& board){
	if(row < 0 || col < 0 || row == board.size() || col == board[0].size()) return true;
	return false;
}

bool canKillMonster(int row, int col, vector<vector<int>>& board, string dir){
	if(isOutsideBoard(row,col,board)) return false;
	
	if(board[row][col]) return true;
	
	bool res = false;
	if(dir == "") res = (canKillMonster(row,col-1,board,"L") || canKillMonster(row,col+1,board,"R") || canKillMonster(row-1,col,board,"T") || canKillMonster(row+1,col,board,"B"));
	else{
		if(dir == "L") res = canKillMonster(row,col-1,board,dir);
		else if(dir == "R") res = canKillMonster(row,col+1,board,dir);
		else if(dir == "T") res = canKillMonster(row-1,col,board,dir);
		else if(dir == "B") res = canKillMonster(row+1,col,board,dir);
	}

	return res;
}

int removeMonsters(vector<vector<int>>& board){
	int n = 10000, m = 10000, total_kills = 0;
	for(int i=n-1; i>=0; i--){
		for(int j=m-1; j>=0; j--){
			if(board[i][j]){
				board[i][j] = 0;
				if(canKillMonster(i,j,board,"")) total_kills++;
				else board[i][j] = 1;  			
			}
		}	
	}
	return total_kills;
}

int main(){
	int n,x,y;
	cin >> n;
	vector<vector<int>> board(3,vector<int>(3,0));
	for(int i=0; i<n; i++){
		cin >> x >> y;
		board[x][y] = 1;
	} 
	
	int killed_mon = removeMonsters(board);
	cout << killed_mon << "\n";
	
	return 0;	
}
