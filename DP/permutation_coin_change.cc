#include<bits/stdc++.h>
using namespace std;

/*
int solve(int coins[], int n, int curr_amt, int total_amt, vector<int>& mem){
	
	if(curr_amt > total_amt) return 0;
	if(curr_amt == total_amt) return 1;
	
	if(mem[curr_amt]) return mem[curr_amt];
	for(int i=0;i<n;i++){
		mem[curr_amt] += solve(coins,n,curr_amt+coins[i],total_amt,mem);
	}
	return mem[curr_amt];
}

int getPossibleCoinPer(int coins[], int n, int total_amt){
	vector<int> mem(total_amt+1,0);
	int ans = solve(coins,n,0,total_amt,mem);
	return ans;
}
*/

int getPossibleCoinPer(int coins[], int n, int tar_amt){
	vector<int> dp(tar_amt+1,0);
	dp[0] = 1;
	for(int curr_amt = 1 ; curr_amt <= tar_amt ; curr_amt++){
		for(int i = 0 ; i < n ; i++){
			int coin = coins[i];
			if(coin <= curr_amt){
				int rem_amt = curr_amt - coin;
				dp[curr_amt] += dp[rem_amt];
			}
		}
	}
	return dp[tar_amt];
}

int main(){
	int n;
	cin>>n;
	int coins[n];
	for(int i=0;i<n;i++) cin>>coins[i];
	
	int amt;
	cin>>amt;
	
	int poss_per_comb = getPossibleCoinPer(coins,n,amt); 
	cout<<poss_per_comb<<"\n";
	
	return 0;
}





// NOTE : we are getting possible permutations(*not combinantions) in answer 
// so for eg. coins[] = {2,3,5}   target amount = 7
// answer is all possible permutaions = (2,2,3)  (2,3,2)  (3,2,2)  (2,5)  (5,2)
// not possible coins combinations of target amount = (2,2,3) (2,5)

