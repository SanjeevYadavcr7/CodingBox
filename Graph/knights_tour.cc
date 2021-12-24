#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>& board);

bool isNotValidMove(int n, int row, int col, vector<vector<bool>>& vis){
	if(row<0 || col<0 || row>=n || col>=n || vis[row][col]) return true;
	return false;
}

void knightTravelling(vector<vector<int>>& board, int size, int row, int col, int step, vector<vector<bool>>& vis){
	
	if(isNotValidMove(size,row,col,vis)) return;
	
	if(step == size*size){
		board[row][col] = step;
		display(board);
		return;
	}
	
	vis[row][col] = true;
	board[row][col] = step;
	knightTravelling(board,size,row-2,col+1,step+1,vis);
	knightTravelling(board,size,row-1,col+2,step+1,vis);
	knightTravelling(board,size,row+1,col+2,step+1,vis);
	knightTravelling(board,size,row+2,col+1,step+1,vis);
	knightTravelling(board,size,row+2,col-1,step+1,vis);
	knightTravelling(board,size,row+1,col-2,step+1,vis);
	knightTravelling(board,size,row-1,col-2,step+1,vis);
	knightTravelling(board,size,row-2,col-1,step+1,vis);
	vis[row][col] = false;
}

void generateKnightPath(vector<vector<int>>& board, int row, int col){
	int n = board.size();
	vector<vector<bool>> vis(n,vector<bool>(n,false));
	knightTravelling(board,n,row,col,1,vis);
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>	board(n,vector<int>(n,0));
	int row,col;
	cin>>row>>col;
	
	generateKnightPath(board,row,col);
	
	return 0;
}













void display(vector<vector<int>>& board){
	cout<<"\n";
	for(vector<int> i:board){
		for(int &j:i) cout<<j<<" ";
		cout<<"\n";
	}
}
