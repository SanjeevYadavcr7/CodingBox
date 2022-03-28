#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& arr){
	for(int& i : arr) cout << i << " ";
	cout << "\n";
}

vector<int> getNextGreaterToRight(vector<int>& nums){
	int n = nums.size(), i = n-1;
	vector<int> res(n);
	stack<int> stk;
	
	while(i>=0){
		if(stk.empty()){
			res[i] = -1;
			stk.push(i--); 
		}
		else{
			while(!stk.empty() && nums[i] > nums[stk.top()]) stk.pop();
			if(stk.empty()) res[i] = -1; 
			else res[i] = nums[stk.top()];
			stk.push(i--);	
		}
	}
	return res;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
	int n = nums1.size(), m = nums2.size();
	unordered_map<int,int> mp;
	vector<int> ans;
	
	for(int i=0; i<m; i++) mp[nums2[i]] = i;
	vector<int> nextGreater = getNextGreaterToRight(nums2); 
	
	for(int& i : nums1) ans.push_back(nextGreater[mp[i]]);
	return ans;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> nums1(n), nums2(m);
	for(int i=0; i<n; i++) cin >> nums1[i];
	for(int i=0; i<m; i++) cin >> nums2[i];
		
	vector<int> res = nextGreaterElement(nums1,nums2);
	display(res);	

	return 0;
}
