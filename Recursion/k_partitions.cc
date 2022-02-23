#include<bits/stdc++.h>
using namespace std;

int cnt = 1;
void display(vector<vector<int>>& arr){
	cout << cnt << ". ";
	for(int i=0; i<arr.size(); i++){
		cout << "[";
		for(int j=0; j<arr[i].size(); j++){
			cout << arr[i][j];
			if(j != arr[i].size()-1) cout << ", ";
		}
		cout << "] ";
	}
	cout << "\n";
	cnt++;
}

void getPartitons(int i, int n, int k, int subsets, vector<vector<int>>& arr){
	if(i > n){
		if(subsets == k) display(arr);
		return;
	}
	
	for(int j=0; j<arr.size(); j++){
		if(arr[j].size() > 0){
			arr[j].push_back(i);
			getPartitons(i+1,n,k,subsets,arr);
			arr[j].pop_back();
		}
		else{
			arr[j].push_back(i);
			getPartitons(i+1,n,k,subsets+1,arr);
			arr[j].pop_back();
			break;
		}
	}
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<vector<int>> partitions(k);
	
	getPartitons(1,n,k,0,partitions);

	return 0;
}
