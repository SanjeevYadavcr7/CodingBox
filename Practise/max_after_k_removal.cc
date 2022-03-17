#include<bits/stdc++.h>
using namespace std;

int maximumTop(vector<int>& nums, int k){
	int n = nums.size();
	if(k == 0){
		if(n >= 1) return nums[0];
		else return -1;
	}
	
	if(k == 1){
		if(n >= 2) return nums[1];
		else return -1;
	}
	
	if(n == 1){
		if(k&1) return -1;
		else return nums[0];
	}
	
	int max_num = INT_MIN;
	for(int i=0; i<max(k-1,n); i++) max_num = max(max_num,nums[i]);
	if(k < n) max_num = max(max_num,nums[k]);
	
	return max_num;
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int max_top = maximumTop(arr,k);
	cout << max_top << "\n";
	
	return 0;
}
