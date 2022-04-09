#include<bits/stdc++.h>
using namespace std;
//typedef pair<int,int> customPair;

// Using QuickSelect

int partition(int l, int r, vector<int>& nums, unordered_map<int,int>& freq){
	int pivot_freq = freq[nums[r]];
	int i = l-1;
	
	for(int j=l; j<r; j++){
		if(freq[nums[j]] < pivot_freq){
			i++;
			swap(nums[i],nums[j]);
		}
	}
	swap(nums[i+1],nums[r]);
	return i+1;
}
	

void quickSelect(int left, int right, int k, vector<int>& nums, unordered_map<int,int>& freq){
	if(left == right) return;
	
	int pivot_idx = partition(left,right,nums,freq);
	
	if(k == pivot_idx) return;
	else if(k < pivot_idx) quickSelect(left,pivot_idx-1,k,nums,freq);
	else quickSelect(pivot_idx+1,right,k,nums,freq);
}


vector<int> topKFrequent(vector<int>& nums, int k){
	vector<int> k_freq_nums(k);
	vector<int> unique;
	unordered_map<int,int> freq;
	
	for(int& i : nums) freq[i]++;
	int n = freq.size();
	for(auto i : freq) unique.push_back(i.first);
	
	quickSelect(0,n-1,n-k,unique,freq);
	
	copy(unique.begin() + n - k, unique.end(), k_freq_nums.begin());
	return k_freq_nums;
}



/*  Using HashMap + Heap | TC: O(NLogN) | SC: O(N)

vector<int> topKFrequent(vector<int>& nums, int k){
	priority_queue<customPair> Q;
	unordered_map<int,int> freq;
	vector<int> ans;
	
	for(int& i : nums) freq[i] += 1;  
	for(auto i:freq) Q.push({i.second,i.first});  
	
	while(k--){
		auto it = Q.top();
		Q.pop();
		ans.push_back(it.second);
	}
	return ans;
}
*/

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	vector<int> ans = topKFrequent(nums,k);
	for(int& i : ans) cout << i << " ";
	cout << "\n";
	
	return 0;
}
