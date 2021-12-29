#include<bits/stdc++.h>
using namespace std;

int minMoves(int arr[], int n){
	int dp[n+1];
	dp[n] = 0;
	for(int i=n-1;i>=0;i--){
		int min_val = 30;
		for(int j=1; j<=arr[i] && i+j<=n; j++){
			int new_val = dp[i+j] + 1;
			min_val = min(min_val,new_val);
		}
		dp[i] = min_val;
	}
	return dp[0];
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int min_moves = minMoves(arr,n);
	cout<<min_moves<<endl;
	
	return 0;
}
