#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>& arr);

vector<vector<int>> dir = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

// TC: O(M*N)  |  SC: O(1)

bool isOutOfBox(int x, int y, int m, int n){
	if(x<0 || y<0 || x == m || y == n) return true;
    return false;
}

int getPopulation(int x,int y, vector<vector<int>>& board){
	int m = board.size(), n = board[0].size();
	int cnt = 0;
	
	for(int i=0; i<8; i++){
		int new_x = x + dir[i][0];
		int new_y = y + dir[i][1];
		if(isOutOfBox(new_x,new_y,m,n)) continue;
		if(board[new_x][new_y] == 1 || board[new_x][new_y] == -1 || board[new_x][new_y] == -4) cnt++;	
	}
	return cnt;
}

void gameOfLife(vector<vector<int>>& board){
	int m = board.size(), n = board[0].size();
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			int population = getPopulation(i,j,board);
			if(board[i][j] == 1){
				if(population < 2 || population > 3) board[i][j] = -1;
				else board[i][j] = -4;
			}
			else{
				if(population == 3) board[i][j] = -3;
				else board[i][j] = -2;
			}
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(board[i][j] == -3 || board[i][j] == -4) board[i][j] = 1;
			else board[i][j] = 0;
		}
	}
}

int main(){
	int m,n;
	cin >> m >> n;
	vector<vector<int>> arr(m,vector<int>(n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin >> arr[i][j];
	
	gameOfLife(arr);
	display(arr);

	return 0;
}





/*------------- Display() --------------*/

void display(vector<vector<int>>& arr){
	for(auto i : arr){
		for(int j : i) cout << j << " ";
		cout << "\n";
	}
}
