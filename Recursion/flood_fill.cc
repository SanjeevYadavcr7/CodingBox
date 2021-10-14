#include<iostream>
#include<vector>
using namespace std;


void solve(vector<vector<int>> maze, int row, int col, string ans, vector<vector<int>> visited){
	
	if(row<0 || col<0 || row == maze.size() || col == maze[0].size() || maze[row][col] == 1 || visited[row][col] == 1) return;
	
	if(row == maze.size()-1 && col == maze[0].size()-1){
		cout<<ans<<endl;
		return;	
	}
	
	visited[row][col] = 1;
	solve(maze,row-1,col,ans+"t", visited);
	solve(maze,row,col-1,ans+"l", visited);
	solve(maze,row+1,col,ans+"d", visited);
	solve(maze,row,col+1,ans+"r", visited);
	
	return;
}


void floodfill(vector<vector<int>> maze) {
	int n = maze.size();
	int m = maze[0].size();
	vector < vector < int >> visited(n, vector < int > (m));
	solve(maze, 0, 0, "", visited);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    floodfill(arr);
    return 0;
}
