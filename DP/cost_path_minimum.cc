#include <iostream>
#include <vector>
using namespace std;

int minCost(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {
	dp[n-1][m-1] = arr[n-1][m-1];
	for(int i=n-2;i>=0;i--) dp[i][m-1] = dp[i+1][m-1] + arr[i][m-1];
	for(int j=m-2;j>=0;j--) dp[n-1][j] = dp[n-1][j+1] + arr[n-1][j];
	
	for(int i=n-2;i>=0;i--){
		for(int j=m-2;j>=0;j--){
			int min_val = min(dp[i+1][j],dp[i][j+1]);
			dp[i][j]  = min_val + arr[i][j];
		}
	}
	return dp[0][0];
}

int main()  {
  int n,m;
  cin>>n>>m;

  vector<vector<int>> arr(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m));
  cout << minCost(n, m, arr, dp)<<"\n";
	
  return 0;
}
