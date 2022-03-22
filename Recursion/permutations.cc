#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>& ans);
vector<vector<int>> ans;

void getPermutation(int idx, vector<int>& temp, vector<int>& nums){
	if(idx == nums.size()){
		ans.push_back(temp);
		return;
	}
	
	for(int i=0; i<nums.size(); i++){
		if(temp[i] == -1){
			temp[i] = nums[idx];
			getPermutation(idx+1,temp,nums);
			temp[i] = -1;
		}
	}
}
	
vector<vector<int>> permute(vector<int>& nums){
	int n = nums.size();
	vector<int> temp(n,-1);
	getPermutation(0,temp,nums);
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	vector<vector<int>> ans = permute(arr);
	display(ans);
	
	return 0; 
}


































void display(vector<vector<int>>& ans){
	int n = ans.size(), m = ans[0].size();
	cout << "[";
	for(int i=0; i<n; i++){
		cout << "[";
		for(int j=0; j<m; j++){
			cout  << ans[i][j];
			if(j != m-1) cout << ", ";
		}
		cout<<"]";
		if(i != n-1) cout << ", ";
	}
	cout << "]\n";
}
