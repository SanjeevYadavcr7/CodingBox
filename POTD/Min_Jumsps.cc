#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<pair<int,int>,int>,vector<int>> pi;

void display(vector<int>& temp){
	int n = temp.size();
	for(int i=0; i<n; i++){
		cout << temp[i];
		if(i != n-1) cout << " -> ";
		else cout << " .\n";
	}
}

void jump(vector<int>& nums){
	int n = nums.size();
	vector<int> dp(n,0);
	
	for(int i=n-2; i>=0; i--){
		int steps = nums[i];
		int min_steps = INT_MAX-1;
		for(int j=1; j<=steps && i+j<n; j++){
			if(dp[i+j] != INT_MAX) min_steps = min(min_steps,dp[i+j]);
		}
		dp[i] = min_steps + 1;
	}
	
	cout << dp[0] << "\n";
	
	queue<pi> Q;
	vector<int> path = {0};
	Q.push({{{0,nums[0]},dp[0]},path});
	
	while(!Q.empty()){
		int size = Q.size();
		while(size--){
			auto it = Q.front();
			int i = it.first.first.first;
			int steps = it.first.first.second;
			int jump = it.first.second;
			vector<int> temp = it.second;
			Q.pop();
			
			if(i == n-1){
				display(temp);
				continue;
			}
			
			int min_jump = jump-1;

			for(int j=1; j<=steps && i+j<n; j++){
				if(dp[i+j] == min_jump){
					path = temp;
					path.push_back(i+j);
					Q.push({{{i+j,nums[i+j]},dp[i+j]},path});
				}
			}
		}
	}
}


int main(){	
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	jump(arr);

	return 0;
}
