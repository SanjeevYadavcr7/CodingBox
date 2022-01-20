#include<bits/stdc++.h>
using namespace std;

int collectGold(int i, int j, vector<vector<int>> &mine, int n, int m){
	if(i<0 || j<0 || i == n || j == m || mine[i][j] == 0 || mine[i][j] == -1) return 0;
	
	int box = mine[i][j];
	int gold = mine[i][j];
	mine[i][j] = -1;
	
	gold += max({collectGold(i+1,j,mine,n,m), collectGold(i-1,j,mine,n,m), collectGold(i,j+1,mine,n,m), collectGold(i,j-1,mine,n,m)});
	
	mine[i][j] = box;
	return gold;
}

int maximizeGold(vector<vector<int>> &mine){
	int max_gold = 0;
	int n = mine.size(), m = mine[0].size();
	vector<vector<bool>> vis(n,vector<bool>(m,false));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mine[i][j]){
				int gold = collectGold(i,j,mine,n,m);
				max_gold = max(max_gold,gold);
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
	
	int gold = maximizeGold(mine);
	cout << gold << "\n";
	
	return 0;
}
