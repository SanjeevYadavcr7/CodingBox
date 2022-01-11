#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void transactions(vector<int> arr, int n, int k) {
	vector<vector<int>> dp(k+1, vector<int>(n,0));
	for(int i=1;i<=k;i++){
		int max_val = dp[i-1][0] - arr[0];
		for(int j=1;j<n;j++){
			int temp_max_val = dp[i-1][j-1] - arr[j-1];
			max_val = max(max_val,temp_max_val);
			
			int max_profit = max(max_val+arr[j],dp[i][j-1]);
			dp[i][j] = max_profit;
			 
		}
	}
	cout<<dp[k][n-1]<<"\n";
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) cin >> arr[i];
  
  int k ;
  cin >> k;
  transactions(arr, n, k);

  return 0;
}
