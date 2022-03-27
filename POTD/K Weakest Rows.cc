#include<bits/stdc++.h>
using namespace std;

bool weakest(pair<int,int>& a, pair<int,int>& b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
	int n = mat.size(), m = mat[0].size();
	vector<int> res;
	vector<pair<int,int>> soldier_map;
	
	for(int i=0; i<n; i++){
		int soldiers = 0;
		for(int j=0; j<m; j++){
			if(!mat[i][j]) break;
			soldiers++;
		}
		soldier_map.push_back({soldiers,i});
	} 
	
	sort(soldier_map.begin(), soldier_map.end(), weakest);
	int i = 0;
	while(k--) res.push_back(soldier_map[i++].second);
	return res;
}

int main(){
	int n,m,k;
	cin >> n >> m;
	vector<vector<int>> arr(n,vector<int>(m));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) cin >> arr[i][j];
		
	cin >> k;
	
	vector<int> ans = kWeakestRows(arr,k);
	for(int &i : ans) cout << i << " ";
	cout << "\n";

	return 0;
}
