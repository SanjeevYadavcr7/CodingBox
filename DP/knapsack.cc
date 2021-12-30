#include <bits/stdc++.h>
using namespace std;

void zeroOneKnapsack(int n, vector<int> val, vector<int> weight, int cap){
	vector<vector<int>> dp(n+1, vector<int>(cap+1,0));
	
	for(int i=1;i<=n;i++){
		int bw = weight[i-1];
		int bv = val[i-1];
		for(int j=1;j<=cap;j++){	
			if(bw <= j){
				int x = dp[i-1][j];
				int y = bv+dp[i-1][j-bw];
				dp[i][j] = max(x,y);
			}
		}
	}
	cout<<dp[n][cap]<<"\n";
}

int main() {
  int n;
  cin >> n;
  vector<int> val(n);
  for (int i=0;i<n;i++) cin>>val[i];

  vector<int> weight(n);
  for (int i=0;i<n;i++) cin>>weight[i];

  int cap;
  cin >> cap;
  zeroOneKnapsack(n, val, weight, cap);

  return 0;
}
