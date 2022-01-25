#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<char>>& arr);

bool canPlaceHorizontally(vector<vector<char>>& board, int i, int j, string word){
	if( j-1 >=0 && board[i][j-1] != '+' ) return false;
	else if( j+word.length() < board[0].size() && board[i][j+word.length()] != '+') return false;
	
	for(int jj=0; jj<word.length(); jj++){
		if(j+jj >= board[0].size()) return false;
		if(board[i][j+jj] == '-' || board[i][j+jj] == word[jj]) continue;
		else return false;
	}
	return true;
}

vector<bool> placeHorizontally(vector<vector<char>>& board, int i, int j, string word){
	vector<bool> placed(word.length(),false);
	
	for(int jj=0; jj<word.length(); jj++){
		if(board[i][j+jj] == '-'){
			board[i][j+jj] = word[jj];
			placed[jj] = true;
		}
	}
	return placed;
}

void unplaceHorizontally(vector<vector<char>>& board,vector<bool>& placed, int i, int j){
	for(int jj=0; jj<placed.size(); jj++){
		if(placed[jj] == true) board[i][j+jj] = '-';
	}
}

bool canPlaceVertically(vector<vector<char>>& board, int i, int j, string word){
	if( i-1 >=0 && board[i-1][j] != '+' ) return false;
	else if( i+word.length() < board.size() && board[i+word.length()][j] != '+') return false;
	
	for(int ii=0; ii<word.length(); ii++){
		if(i+ii >= board.size()) return false;
		if(board[i+ii][j] == '-' || board[i+ii][j] == word[ii]) continue;
		else return false;
	}
	return true;
}

vector<bool> placeVertically(vector<vector<char>>& board, int i, int j, string word){
	vector<bool> placed(word.length(),false);
	for(int ii=0; ii<word.length(); ii++){
		if(board[i+ii][j] == '-'){
			board[i+ii][j] = word[ii];
			placed[ii] = true;
		}
	}
	return placed;
}

void unplaceVertically(vector<vector<char>>& board,vector<bool>& placed, int i, int j){
	for(int ii=0; ii<placed.size(); ii++){
		if(placed[ii] == true) board[i+ii][j] = '-';
	}
}

void solve(vector<vector<char>>& board, vector<string>& words, int idx){
	if(idx == words.size()){
		display(board);
		return;
	}
	
	string word = words[idx];
	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[0].size(); j++){
			if(board[i][j] == '-' || board[i][j] == word[0]){
				
				if(canPlaceHorizontally(board,i,j,word)){
					vector<bool> placed = placeHorizontally(board,i,j,word);
					solve(board, words, idx+1);
					unplaceHorizontally(board,placed,i,j);
				}
				
				if(canPlaceVertically(board,i,j,word)){
					vector<bool> placed = placeVertically(board,i,j,word);
					solve(board, words, idx+1);
					unplaceVertically(board,placed,i,j);
				}	
			}
		}
	}
}


void solveCrossword(vector<vector<char>>& board, vector<string>& words){
	solve(board,words,0);
}

int main(){
	int m = 10;
	vector<vector<char>> arr(m,vector<char>(m,' '));
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++) cin >> arr[i][j];
	}
	
	int n;
	cin >> n;
	vector<string> words(n);
	for(int i=0; i<n; i++) cin >> words[i];
	
	solveCrossword(arr,words);
	
	return 0;
}



































void display(vector<vector<char>>& arr){
	cout << "\n";
	for(auto i : arr){
		for(char j : i) cout << j << " ";
		cout << "\n"; 
	}
}
