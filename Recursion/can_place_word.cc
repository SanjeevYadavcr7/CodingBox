#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<char>>& arr);

void placingWord(vector<vector<char>>& board, int i, int j, string word, int idx, int dir){
	if(idx == word.length()){
		display(board);
		return;
	}
	
	if(i >= board.size() || j >= board[0].size() || board[i][j] == '+' ) return;
	
	board[i][j] = word[idx];
	if(dir == -1){
		placingWord(board,i+1,j,word,idx+1,0);
		placingWord(board,i,j+1,word,idx+1,1);
	}
	else if(dir == 0) placingWord(board,i+1,j,word,idx+1,0);
	else if(dir == 1) placingWord(board,i,j+1,word,idx+1,1);
	board[i][j] = '-';
}

bool placeWordInCrossword(vector<vector<char>>& board, string word) {
	int n = board.size(), m = board[0].size();
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			if(board[i][j] != '+') placingWord(board,i,j,word,0,-1);	
		}
	return true;
}

int main(){
	int m,n;
	cin >> m >> n;
	vector<vector<char>> board(m, vector<char>(n,' '));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) cin >> board[i][j];
	
	string word;
	cin >> word;
	
	if(placeWordInCrossword(board,word)) cout << "true";
	else cout << "false";
	
	cout << "\n";

	return 0;
}






























void display(vector<vector<char>>& arr){
	cout << "\n";
	for(auto i : arr){
		for(char j : i) cout << j << " ";
		cout << "\n"; 
	}
}
