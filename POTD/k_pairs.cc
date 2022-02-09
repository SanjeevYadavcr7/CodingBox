#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int>& nums, int k){
	int pairs = 0, n = nums.size();
	map<int,int> mp;
	for(int &i : nums) mp[i] += 1;
	for(auto i : mp){
		int a = i.first;
		int freq_a = i.second;
		if(k>0 && mp[k+a] > 0) pairs++;
		else if(k == 0 && mp[a] > 0) pairs++;
	}
	return pairs;
}

int main(){	
	int n,k;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	cin >> k;
	
	int no_of_pairs = findPairs(arr,k);
	cout << no_of_pairs << "\n";

	return 0;
}





































/*
int findPairs(vector<int>& nums, int k){
	unordered_map<int,int> mp;
	set<pair<int,int>> pairs;
	
	for(int& i : nums) mp[i] += 1;
	for(int& curr_num : nums){
		mp[curr_num] -= 1;
		
		int x = curr_num + k;
		int y = curr_num - k;
		
		if(mp[x] > 0){
			if(x > curr_num) pairs.insert({curr_num,x});
			else pairs.insert({x,curr_num});
		}
		
		if(mp[y] > 0){
			if(y > curr_num) pairs.insert({curr_num,y});
			else pairs.insert({y,curr_num});
		}
		
		mp[curr_num] += 1;
	}
	
	return pairs.size();
}
*/
