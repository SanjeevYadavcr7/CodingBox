#include<bits/stdc++.h>
using namespace std;
bool boundaryCrossed(int row, int col,vector<vector<int>>& arr){
	if(row < 0 || row == arr.size() || col < 0 || col == arr[0].size()) return true;
	return false;
}

int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> Q;
        
        int oranges = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = true;
                    Q.push({i,j});  
                }       
                if(grid[i][j] != 0) oranges++; 
            }    
        }
        
        int time = 0, t_x = 0;
		
        while(!Q.empty()){
        	queue<pair<int,int>> temp;
        	int x = Q.size(); 
        	while(x--){
        		auto curr_cell = Q.front();
		        int x = curr_cell.first, y = curr_cell.second;
		        Q.pop();
		        t_x++;
		        for(auto move : dir){
		            int new_x = x + move.first;
		            int new_y = y + move.second;
		            
		            if(boundaryCrossed(new_x, new_y, grid)) continue;
		            if(grid[new_x][new_y] == 0 || vis[new_x][new_y]) continue;
		            vis[new_x][new_y] = true;                

		            pair<int,int> new_cell = {new_x,new_y};
		            temp.push({new_cell});
		        }
		    }
		    Q = temp;
		    if(temp.size() > 0) time++;
        }
        
        if(oranges > t_x) return -1;
     	return time;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> box(n,vector<int>(m,0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> box[i][j];
	}
	
	int time_taken = orangesRotting(box);
	cout << time_taken << "\n";
	
	return 0;
}
