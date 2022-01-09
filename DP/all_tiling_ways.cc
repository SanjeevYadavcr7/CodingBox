#include<bits/stdc++.h>
using namespace std;

int doTiling(int n, int m){
	vector<int> dp(n+1);
	for(int i=1;i<=n;i++){
		if(i < m) dp[i] = 1;
		else if(i == m) dp[i] = 2;
		else dp[i] = dp[i-1] + dp[i-m];
	}
	return dp[n];
}

int main(){
    int n,m;
    cin>>n>>m;
    int tiling_ways = doTiling(n,m);
    cout<<tiling_ways<<"\n";
    
    return 0;
}
