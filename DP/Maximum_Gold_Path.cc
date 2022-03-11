#include<bits/stdc++.h>
using namespace std;

bool isOutOfBox(int row, int col, vector<vector<int>>& mine){
	if(row < 0 || row == mine.size() || col<0 || col == mine[0].size()) return true;
	return false;
}

void printAllGoldPaths(vector<vector<int>>& mine){
	int n = mine.size(), m = mine[0].size();
	int max_gold = INT_MIN;
	vector<vector<int>> dir = {{-1,1}, {0,1}, {1,1}};
	
	for(int j=m-2; j>=0; j--){
		for(int i=0; i<n; i++){
			int gold = 0;
			for(int k=0; k<3; k++){
				int x = i + dir[k][0];
				int y = j + dir[k][1];
				if(isOutOfBox(x,y,mine)) continue;
				gold = max(gold,mine[x][y]); 
			}
			mine[i][j] += gold;
			max_gold = max(max_gold,mine[i][j]);
		}
	}
	
	queue<pair<pair<int,int>,string>> Q;
	for(int i=0; i<n; i++){
		if(mine[i][0] == max_gold) Q.push({{i,0},to_string(i)+" "});
	} 
	cout << max_gold << "\n";

	while(!Q.empty()){
		int size = Q.size();
		while(size--){
			auto it = Q.front();
			int x = it.first.first;
			int y = it.first.second;
			string path = it.second;
			Q.pop();
			
			if(y == m-1){
				cout << path << "\n";
				continue;
			}
			
			int d1_gold = isOutOfBox(x-1,y+1,mine) ? 0 : mine[x-1][y+1];
			int d2_gold = isOutOfBox(x,y+1,mine) ? 0 : mine[x][y+1];
			int d3_gold = isOutOfBox(x+1,y+1,mine) ? 0 : mine[x+1][y+1];
			
			max_gold = max(d1_gold,max(d2_gold,d3_gold));
			
			for(int k=0; k<3; k++){
				int new_x = x + dir[k][0];
				int new_y = y + dir[k][1];
				if(isOutOfBox(new_x,new_y,mine)) continue;
				if(mine[new_x][new_y] == max_gold){
					string new_path = path + "d" + to_string(k+1) + " ";
					Q.push({{new_x,new_y},new_path});
				}
			}
		}	
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> maze(n,vector<int>(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> maze[i][j];
	}
	
	printAllGoldPaths(maze);

	return 0;
}




