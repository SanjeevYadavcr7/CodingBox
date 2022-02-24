#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums){
	int n = nums.size(), total = 0;
	for(int& i : nums) total += i;
	if(total&1) return false;
	
	int tar = total/2;
	bool dp[n+1][tar+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=tar; j++){
			if(i == 0 && j == 0) dp[i][j] = true;
			else if(i == 0) dp[i][j] = false;
			else if(j == 0) dp[i][j] = true;
			else{
				if(dp[i-1][j] == true) dp[i][j] = true;
				else{
					int val = nums[i-1];
					if(j >= val){
						if(dp[i-1][j-val] == true) dp[i][j] = true;
					}
				}
			} 
		}
	}
	return dp[n][tar];
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
