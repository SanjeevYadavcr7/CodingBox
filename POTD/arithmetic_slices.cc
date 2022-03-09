#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& arr){
	cout << "\narr[] = ";
	for(int& i : arr) cout << i << " ";
}

/* Recursive approach

bool isValidSlice(vector<int>& arr){
	int n = arr.size();
	if(n < 3) return false;
	int diff = arr[1] - arr[0], cnt = 1;
	for(int i=2; i<n; i++){
		int curr_diff = arr[i] - arr[i-1];
		if(curr_diff != diff) return false;
	}
	return true;
}

void solve(int idx, vector<int>& nums, int& ans, vector<int> subarray){
	if(idx == nums.size()){
		if(isValidSlice(subarray)){
			display(subarray);
			ans += 1;
		} 
		return;	
	}
	
	if(subarray.size() >= 3){
		if(isValidSlice(subarray)){
			display(subarray);
			ans += 1;
		}
	}
	
	if(subarray.size() > 0){
		subarray.push_back(nums[idx]);
		solve(idx+1,nums,ans,subarray);		
	}
	else{
		solve(idx+1,nums,ans,subarray);
		subarray.push_back(nums[idx]);
		solve(idx+1,nums,ans,subarray);
	}
}

int numberOfArithmeticSlices(vector<int>& nums){
	int n = nums.size();
	if(n < 3) return 0;
	
	int ans = 0;
	vector<int> subarray;
	solve(0,nums,ans,subarray);
	return ans;
}
*/

int numberOfArithmeticSlices(vector<int>& nums){
	int n = nums.size();
	if(n<3) return 0;
	
	int cnt = 0;
	vector<int> slices(n);
	slices[0] = slices[1] = 0;
	for(int i=2; i<n; i++){
		if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
			slices[i] = (slices[i-1] + 1);
			cnt += slices[i];	
		}
	}
	return cnt;
}


int main(){	
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	int slices = numberOfArithmeticSlices(nums);
	cout << slices << "\n";
	
	return 0;
}




















