#include <bits/stdc++.h>
using namespace std;

void unboundedKnapsack(int n, vector<int> val, vector<int> weight, int cap){
	int dp[cap+1] = {0};
	for(int cw=1;cw<=cap;cw++){
		for(int j=0;j<n;j++){
			int bw = weight[j];
			if(cw >= bw){
				int bv = val[j] + dp[cw-bw];
				dp[cw] = max(bv,dp[cw]);
			}
		}
	}
	cout<<dp[cap]<<"\n";
}


int main() {
  int n;
  cin>>n;
  vector<int> val(n);
  for (int i = 0; i < n; i++) cin >> val[i];
  
  vector<int> weight(n);
  for (int i = 0; i < n; i++) cin >> weight[i];
  
  int cap;
  cin >> cap;

  unboundedKnapsack(n, val, weight, cap);

  return 0;
}
