#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>& arr){
	cout << "[";
	for(int i=0; i<arr.size(); i++){
		cout << "[";
		for(int j=0; j<arr[i].size(); j++){
			cout << arr[i][j];
			if(j != arr[i].size()-1) cout << ",";
		}
		cout << "]";
		if(i != arr.size()-1) cout << ",";
	}
	cout << "]\n";
}

void getSubsets(vector<int>& nums, int idx, vector<int> temp, vector<vector<int>>& arr){
	if(idx == nums.size()){
		arr.push_back(temp);
		return;
	}
	
	getSubsets(nums,idx+1,temp,arr);
	temp.push_back(nums[idx]);
	getSubsets(nums,idx+1,temp,arr);
}

vector<vector<int>> subsets(vector<int>& nums){
	vector<int> temp;
	vector<vector<int>> arr;
	getSubsets(nums,0,temp,arr); 
	return arr;       
}

int main(){
	int n;
	cin >> n;
	vector<int> nums(n,0);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	vector<vector<int>> new_arr = subsets(nums);
	display(new_arr);

	return 0;
}
