#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> ans);

/*
bool areEqualSumSubsets(int idx, int curr_sum, int total, vector<int>& nums){
        if(curr_sum*2 == total) return true;
        if(curr_sum > total/2 || idx >= nums.size()) return false;
        
	return areEqualSumSubsets(idx+1,curr_sum,total,nums) || areEqualSumSubsets(idx+1,curr_sum+nums[idx],total,nums);     
}
    
    bool canPartition(vector<int>& nums){
        int n = nums.size(), k = 2, total = 0;
        vector<vector<int>> subsets(k);
        
        for(int& i : nums) total += i;
        if(total&1) return false;
            
        return areEqualSumSubsets(0,0,total,nums);
    }
*/

bool isEqualSumSubsets(vector<vector<int>>& subsets){	
	int sum1 = 0, sum2 = 0;
	for(int j=0; j<subsets[0].size(); j++) sum1 += subsets[0][j];
	for(int j=0; j<subsets[1].size(); j++) sum2 += subsets[1][j];
	return sum1 == sum2;
}

bool getSubsets(int idx, int n, int nos, int k, vector<int>&nums, vector<vector<int>>& subsets){
	if(idx == n){
		if(k == nos){
			if(isEqualSumSubsets(subsets)) return true;
		}
		return false;
	}	
	
	for(int j=0; j<subsets.size(); j++){
		if(subsets[j].size() > 0){
			subsets[j].push_back(nums[idx]);
			if(getSubsets(idx+1,n,nos,k,nums,subsets)) return true;
			subsets[j].pop_back();		
		}
		else{
			subsets[j].push_back(nums[idx]);
			if(getSubsets(idx+1,n,nos+1,k,nums,subsets)) return true;
			subsets[j].pop_back();
			break;
		}
	}
	return false;
}

bool canPartition(vector<int>& nums){
	int n = nums.size(), k = 2;
	vector<vector<int>> subsets(k);
	
	return getSubsets(0,n,0,k,nums,subsets);
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	if(canPartition(arr)) cout << "true";
	else cout << "false";
	cout << "\n";
	
	return 0;
}












































void display(vector<vector<int>> ans){
	for(int i=0; i<ans.size(); i++){
		cout << "[";
		for(int j=0; j<ans[i].size(); j++){
			cout << ans[i][j];
			if(j != ans[i].size()-1) cout << ",";
		}
		cout << "] ";
	}
	cout << "\n";
}
