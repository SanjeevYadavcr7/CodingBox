#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pi;

bool isOutOfGrid(int row, int col, vector<vector<int>>& grid){
        if(row<0 || col<0 || row == grid.size() || col == grid[0].size()) return true;
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int max_time = INT_MIN;
        vector<pair<int,int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        priority_queue<pi, vector<pi>, greater<pi>> Q;
        
        Q.push({grid[0][0],{0,0}});
        while(!Q.empty()){
            auto it = Q.top();
            int time = it.first;
            int x = it.second.first;
            int y = it.second.second;
            Q.pop();
            
            max_time = max(time,max_time);
            if(x == n-1 && y == m-1) break;
            
            if(grid[x][y] == -1) continue;
            grid[x][y] = -1;
            
            for(auto i : dir){
                int nei_x = x + i.first;
                int nei_y = y + i.second;
                if(!isOutOfGrid(nei_x,nei_y,grid)) Q.push({grid[nei_x][nei_y],{nei_x,nei_y}});
            }
        }
        
        return max_time;
    }

int main(){
	int n,m;
	cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j) cin>>grid[i][j];
    }
        
    cout<<swimInWater(grid)<<"\n";

	return 0;
}
