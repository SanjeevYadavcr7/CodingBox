#include<bits/stdc++.h>
using namespace std;

bool boundaryCrossed(int row, int col,vector<vector<int>>& arr){
	if(row < 0 || row >= arr.size() || col < 0 || col >= arr[0].size()) return true;
	return false;
}

int visitMatrix(int i, int j, vector<vector<int>>& arr, vector<vector<bool>>& vis){
	if(boundaryCrossed(i,j,arr)) return INT_MIN;
	if(vis[i][j]) return arr[i][j];
	
	return dis;
}	

vector<vector<int>> updateMatrix(vector<vector<int>>& arr){
	int n = arr.size(), m = arr[0].size();
	vector<vector<bool>> vis(n,vector<bool>(m,false));		
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == 0) vis[i][j] = true;
			else arr[i][j] = visitMatrix(i,j,arr,vis);
		}
	}
	return arr;
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
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
