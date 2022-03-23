#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>& arr);
vector<vector<int>> ans;

void permute(int cb, int tb, vector<bool>& used, int usf, int r, string psf){
	if(cb > tb){
		if(usf == r) cout << psf << "\n";
		return;
	}
	
	for(int i=0; i<r; i++){
		if(!used[i]){
			used[i] = true;
			permute(cb+1,tb,used,usf+1,r,psf+to_string(i+1));
			used[i] = false;
		}
	}
	permute(cb+1,tb,used,usf,r,psf+to_string(0));
}

void getPermutation(int n, int r){
	vector<bool> used(r);
	permute(1,n,used,0,r,"");
}

int main(){
	int n,r;
	cin >> n >> r;
	getPermutation(n,r);
	return 0;
}







































void display(vector<vector<int>>& arr){
	int n = arr.size(), m = arr[0].size();
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cout << arr[i][j];
		cout << "\n";
	}
}
