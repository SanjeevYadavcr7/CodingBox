#include<bits/stdc++.h>
using namespace std;

int doPairing(int n){
	vector<int> dp(n+1,0);
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=n;i++) dp[i] = dp[i-1] + (i-1) * dp[i-2];
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	
	int total_pairs = doPairing(n);
	cout<<total_pairs<<"\n";

	return 0;
}
