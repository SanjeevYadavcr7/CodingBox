#include<bits/stdc++.h>
using namespace std;


// Using QuickSelect | Acerage Case: TC: O(N)

int getPivotIndex(int l, int r, vector<int>& unique, unordered_map<int,int>& freq){
	int i = l-1;
	int pivot_freq = freq[unique[r]];
	for(int j=l; j<r; j++){
		if(freq[j] < pivot_freq){
			i++;
			swap(unique[i],unique[j]);
		}
	}
	swap(unique[i+1],unique[r]);
	return i+1;
}

void getKthFrequentIdx(int l, int r, int k, vector<int>& unique, unordered_map<int,int>& freq){
	if(l == r) return;
	
	int pivot = getPivotIndex(l,r,unique,freq);
	if(pivot == k) return;
	else if(k < pivot) getKthFrequentIdx(l,pivot-1,k,unique,freq);
	else getKthFrequentIdx(pivot+1,r,k,unique,freq);
}

vector<int> topKFrequent(vector<int>& nums, int k){
	int n = nums.size();
	unordered_map<int,int> freq;
	vector<int> k_freq_nums(k);
	vector<int> unique;
	
	for(int& i : nums) freq[i]++;
	for(auto& i : freq) unique.push_back(i.first);
	
	n = freq.size();
	getKthFrequentIdx(0,n-1,n-k,unique,freq);
	copy(unique.begin() + n - k, unique.end(), k_freq_nums.begin());
	return k_freq_nums;
}



/*  Using HashMap + Heap | TC: O(NLogN) | SC: O(N)

typedef pair<int,int> customPair;
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
