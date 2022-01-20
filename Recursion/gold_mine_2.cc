#include<bits/stdc++.h>
using namespace std;

int max_gold = INT_MIN;

void visitMine(int i, int j, vector<vector<int>> &mine,vector<vector<bool>> &vis, int n, int m, int &cost){
	if(i<0 || i == n || j<0 || j == m || mine[i][j] == 0 || vis[i][j]){
		max_gold = max(max_gold,cost);
		return;
	} 
	
	cost += mine[i][j];
	vis[i][j] = true;

	visitMine(i+1,j,mine,vis,n,m,cost);
	visitMine(i-1,j,mine,vis,n,m,cost);
	visitMine(i,j+1,mine,vis,n,m,cost);
	visitMine(i,j-1,mine,vis,n,m,cost);
}

int maximizeGold(vector<vector<int>> &mine,int n, int m){

	vector<vector<bool>> vis(n,vector<bool>(m,false));
	
	for(int i=0; i<n; i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] && mine[i][j] != 0){
				int cost = 0;
				visitMine(i,j,mine,vis,n,m,cost);
			}	
		}
	}
	
	return max_gold;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mine(n, vector<int>(m,0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> mine[i][j];
	}
	
	int gold = maximizeGold(mine,n,m);
	cout << gold << "\n";
	
	return 0;
}
