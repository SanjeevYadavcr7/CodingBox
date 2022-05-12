#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
void getPermutations(int n, vector<int> perSet,unordered_map<int,int>& freq) {
	if(perSet.size() == n) {
		res.push_back(perSet);
		return;
	}
	
	for(auto& i : freq) {
		if(i.second > 0) {
			perSet.push_back(i.first);
			i.second--;
			getPermutations(n,perSet,freq);
			i.second++;
			perSet.pop_back();
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<int> perSet;
	unordered_map<int,int> freq;
	
	for(int i : nums) freq[i] += 1;
	getPermutations(nums.size(),perSet,freq);
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	vector<vector<int>> res = permuteUnique(nums);
	for(auto i : res) {
		for(int j : i) cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}
