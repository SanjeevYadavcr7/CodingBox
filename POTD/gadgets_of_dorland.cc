#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

vector<int> TopK(vector<int>& array, int k){
	unordered_map<int,int> mp;
	for(int& i : array) mp[i] += 1;
	
	vector<pair<int,int>> arr;
	for(auto& it:mp) arr.push_back(it);
	
	sort(arr.begin(), arr.end(), cmp);
	vector<int> ans;
	for(auto& it:arr){
		ans.push_back(it.first);
		k--;
		if(k == 0) break; 
	}
	return ans;
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
		
	vector<int> ans = TopK(arr,k);
	for(int& i : ans) cout << i << " ";
	cout << "\n";

	return 0;
}
