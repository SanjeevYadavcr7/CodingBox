#include<bits/stdc++.h>
using namespace std;

   void display(vector<vector<char>>& board){
        cout << "[";
        for(int i=0; i<n; i++){
            cout << "[";
            for(int j=0; j<n; j++){
                cout << board[i][j];
                if(j != n-1) cout << ",";
            }
            cout << "]";
            if(i != n-1) cout << ",";
        }
        cout << "]";
    } 
    
    bool isValidCell(vector<vector<char>>& board, int x, int y, char val){
        for(int i=0; i<n; i++){
            if(board[i][y] == val) return false;
        }
        
        for(int j=0; j<n; j++){
            if(board[x][j] == val) return false;
        }
        
        int smi = 3*(x/3), smj = 3*(y/3);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[smi+i][smj+j] == val) return false;
            }
        }
        return true;
    }
    
    void sudokuSolver(vector<vector<char>>& board, int i, int j) {
        if(i == n){
            display(board);
            return;
        }
        
        int nx_i = 0, nx_j = 0;
        if(j == n-1){
            nx_i = i+1;
            nx_j = 0;
        }
        else{
            nx_i = i;
            nx_j = j+1;
        }
        
        if(board[i][j] != '0') sudokuSolver(board,nx_i,nx_j);
        else{
            for(int op=1; op<n; op++){
                char ch = op+'0';
                if(isValidCell(board,i,j,ch)){
                    board[i][j] = ch;
                    sudokuSolver(board,nx_i,nx_j);
                    board[i][j] = '0';
                }
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board,0,0);    
    }
    
 int main(){
 	int n = 9;
	vector<vector<char>> arr(n, vector<char>(n,'0'));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) cin >> arr[i][j];
	
	solveSudoku(arr);
	
	return 0;
 }
