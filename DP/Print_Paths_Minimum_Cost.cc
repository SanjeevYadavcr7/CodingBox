#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pi;

void printAllMinCostPaths(vector<vector<int>>& maze){
	int n = maze.size(), m = maze[0].size();
	
	for(int i=1; i<n; i++) maze[i][0] += maze[i-1][0];
	for(int j=1; j<m; j++) maze[0][j] += maze[0][j-1]; 
	
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			maze[i][j] += min(maze[i-1][j], maze[i][j-1]);
		}
	}
	cout << maze[n-1][m-1] << "\n";
}

/*
bool isOutOfMaze(int row, int col,vector<vector<int>>& maze){
	if(row == maze.size() || col == maze[0].size()) return true;
	return false;
}

void printAllMinCostPaths(vector<vector<int>>& maze){
		int n = maze.size(), m = maze[0].size();
		priority_queue<pi,vector<pi>,greater<pi>> Q;
		vector<pair<int,int>> dir = {{0,1},{1,0}};
		
		Q.push({maze[0][0],{0,0}});
		int min_cost = INT_MAX;
		while(!Q.empty()){
			auto it = Q.top();
			int curr_cost = it.first;
			int x = it.second.first;
			int y = it.second.second;
			Q.pop();
			
			if(x == n-1 && y == m-1){
				min_cost = min(min_cost,curr_cost);
				continue;
			}
			
			for(int i=0; i<2; i++){
				int new_x = x + dir[i].first;
				int new_y = y + dir[i].second;
				if(isOutOfMaze(new_x,new_y,maze)) continue;
				int cost_till_now = curr_cost + maze[new_x][new_y];  
				Q.push({cost_till_now, {new_x,new_y}});
			}
		}
		cout << "Minimum Cost = " << min_cost << "\n";
}
*/

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> maze(n,vector<int>(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> maze[i][j];
	}
	
	printAllMinCostPaths(maze);

	return 0;
}
