#include<bits/stdc++.h>
using namespace std;

long long int doPartitioning(int n, int k){
	vector<vector<long long int>> dp(k+1,vector<long long int>(n+1,0));
	
	for(int j=1;j<=n;j++) dp[1][j] = 1;
	
	for(int i=2;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(i > j) dp[i][j] = 0;
			else if(i == j) dp[i][j] = 1;
			else dp[i][j] = i * dp[i][j-1] + dp[i-1][j-1];	
		}
	}
	
	return dp[k][n];
}	

int main(){
	int n,k;
	cin>>n>>k;
	long long int partitoning_ways = doPartitioning(n,k);
	cout<<partitoning_ways<<"\n";
	
	return 0;
}
