#include<bits/stdc++.h>
using namespace std;

bool boundaryCrossed(int row, int col,vector<vector<int>>& arr){
	if(row < 0 || row == arr.size() || col < 0 || col == arr[0].size()) return true;
	return false;
}

vector<vector<int>> multiSourceBFS(vector<vector<int>>& arr){
	int n = arr.size(), m = arr[0].size();
	vector<pair<int,int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
	vector<vector<bool>> vis(n, vector<bool>(m,false));
	vector<vector<int>> dis(n,vector<int>(m,0));
	queue<pair<int,int>> source;
	
	for(int x=0; x<n; x++){
		for(int y=0; y<m; y++){
			if(!arr[x][y]){
				source.push({x,y});
				vis[x][y] = true;
			}
		}
	}
	
	while(!source.empty()){
		auto curr_source = source.front();
		int x = curr_source.first;
		int y = curr_source.second;
		source.pop();
		
		for(auto move : dir){
			int new_x = x + move.first;
			int new_y = y + move.second;
			
			if(boundaryCrossed(new_x, new_y, arr)) continue;
			if(vis[new_x][new_y]) continue;
			
			pair<int,int> new_source = {new_x, new_y};
			source.push(new_source);
			vis[new_x][new_y] = true;
			dis[new_x][new_y] = dis[x][y] + 1;
		}
	}
	
	return dis;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& arr){
	return multiSourceBFS(arr);	
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
    
    vector<vector<int>>ans = updateMatrix(arr);
    
    cout << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
