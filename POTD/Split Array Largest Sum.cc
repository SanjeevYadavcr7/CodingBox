#include<bits/stdc++.h>
using namespace std;

bool isPossibleSum(int temp, vector<int>& nums, int k){
	int sum = 0;
	int cnt = 1;
	for(int& j : nums){
		sum += j;
		if(sum > temp){
			cnt++;
			sum = j;
		}
	}
	return (cnt <= k);
}

int splitArray(vector<int>& nums, int m){
	int n = nums.size();
	int min_sum = 0, max_sum = 0;
	
	for(int& i : nums) max_sum += i, min_sum = max(min_sum,i);
	
	int ans = 0;
	int low = min_sum;
	int high = max_sum;
	while(low < high){
		int poss_ans = (high-low)/2+low;
		if(isPossibleSum(poss_ans,nums,m)){
			ans = poss_ans;
			high = poss_ans - 1;
		} 
		else low = poss_ans + 1;
	}
	return ans;
}


/*
Approach: Wrong | Permutation of partitions are being generated  

void display(vector<vector<int>>& arr){
	for(auto i : arr){
		for(int j : i) cout << j << " ";
		cout << "| ";
	}
		
	cout << " | ";
}

int max_res = INT_MAX, min_res;

void getMinLargestSum(vector<vector<int>>& ans){
	int sum = 0;
	int max_sum = INT_MIN, min_sum = INT_MAX;
	for(auto i : ans){
		sum = 0;
		for(int& j : i) sum += j;
		max_sum = max(max_sum,sum);
		min_sum = min(min_sum,sum);
	}
	
	max_sum = max(max_sum,min_sum);	
	cout << "max = " << max_sum << " | min_sum = " << min_sum << "\n"; 
    if(max_sum < max_res){
    	max_res = max_sum;
    	min_res = min_sum;
    }
    cout << "\n";
}

void doPartition(int idx, int parts, int k, vector<int>& nums, vector<vector<int>>& ans){
	if(idx == nums.size()){
		if(k == parts){
			display(ans);
			getMinLargestSum(ans);
		}
		return;
	}
	
	for(int i=0; i<ans.size(); i++){
		if(ans[i].size() > 0){
			ans[i].push_back(nums[idx]);
			doPartition(idx+1,parts,k,nums,ans);		
			ans[i].pop_back();
		}
		else{
			ans[i].push_back(nums[idx]);
			doPartition(idx+1,parts+1,k,nums,ans);		
			ans[i].pop_back();
			break;
		}
	}
}

int splitArray(vector<int>& nums, int m){
	string str = "";
	for(int &i : nums) str += to_string(i);
	
	vector<vector<int>> partitions(m);	
	doPartition(0,0,m,nums,partitions);		
	
	return min_res;
}
*/

int main(){	
	int n,m;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	cin >> m;
	
	int parts = splitArray(arr,m);
	cout << parts << "\n";

	return 0;
}
