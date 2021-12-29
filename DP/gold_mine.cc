#include <bits/stdc++.h>
using namespace std;

int collectGold(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp){
	for(int i=0;i<n;i++) dp[i][0] = arr[i][0];
	
	for(int j=1;j<m;j++){
		for(int i=0;i<n;i++){
			
			int val1 = (i>0) ? dp[i-1][j-1] : 0;
			int val2 = dp[i][j-1];	
			int val3 = (i<n-1) ? dp[i+1][j-1] : 0;
			
			int max_val = max(val1, max(val2,val3));
			dp[i][j] = max_val+arr[i][j];
		}
	}
  	
  	int max_gold = 0;
  	for(int i=0;i<n;i++) max_gold = max(max_gold,dp[i][m-1]);
  			
 	return max_gold;
}



int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m, 0));
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];

  vector<vector<int>> dp(n, vector<int>(m, 0));
  cout << collectGold(n, m, arr, dp)<<"\n";
  
  return 0;
  
}
