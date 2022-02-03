#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;

    bool isOutofBoundary(int i, int j, int n, int m){
        if(i < 0 || i == n || j < 0 || j == m) return true;
        return false;
    }
    
    void display(vector<vector<int>>& grid){
    	cout << "\n";
    	for(auto i : grid){
    		for(int j : i) cout << j << " ";
    		cout << "\n";
    	}
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<pair<int,int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;  
                    q.push({i,j});
                    cnt++;
                } 
                else grid[i][j] = INT_MAX;
            }
        }
        
        if(cnt == 0 || cnt == n*m) return -1;
        
        int max_d = INT_MIN;
        
        while(!q.empty()){
        	
        	queue<pair<int,int>> temp;
        	while(!q.empty()){
        		auto it = q.front();
				int x = it.first, y = it.second;
				q.pop();
				
				vis[x][y]= true;
				
				for(auto move : dir){
					int new_x = x + move.first, new_y = y + move.second;
					if(isOutofBoundary(new_x,new_y,n,m) || vis[new_x][new_y]) continue;
					int new_dis = grid[x][y]+1;
					if(new_dis < grid[new_x][new_y]){
						grid[new_x][new_y] = new_dis;
						max_d = max(new_dis,max_d);
						temp.push({new_x,new_y});
					}
				}
        	}
			if(temp.size() > 0) q = temp;
        }
        return max_d;
    }
    
    
int main(){
    int n;
    cin>>n;
    
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }

    cout<<maxDistance(arr) << "\n";
	return 0;
}


