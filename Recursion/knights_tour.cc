#include<bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<int>> chess){
	int n = chess.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<chess[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}


void printKnightsTour(vector<vector<int>> &chess, int r,int c, int upcomingMove){
	int n = chess.size();
	
	if(r < 0 || c < 0 || r >= chess.size() || c >= chess.size() || chess[r][c]>0) return;
	else if(upcomingMove == n*n){
		chess[r][c] = upcomingMove;
		displayBoard(chess);
		chess[r][c] = 0;
		return;
	}
	
	chess[r][c] = upcomingMove;
	
	// right side
	printKnightsTour(chess, r-2, c+1, upcomingMove+1);
	printKnightsTour(chess, r-1, c+2, upcomingMove+1);
	printKnightsTour(chess, r+1, c+2, upcomingMove+1);
	printKnightsTour(chess, r+2, c+1, upcomingMove+1);

	// left side
	printKnightsTour(chess, r+2, c-1, upcomingMove+1);
	printKnightsTour(chess, r+1, c-2, upcomingMove+1);
	printKnightsTour(chess, r-1, c-2, upcomingMove+1);
	printKnightsTour(chess, r-2, c-1, upcomingMove+1);
	
	chess[r][c] = 0;
	
	return;

}

int main(){
	int n,x,y;
	cin>>n>>x>>y;
	vector<vector<int>> chess(n, vector<int>(n));
	
	printKnightsTour(chess, x, y, 1);
		
	return 0;
}
