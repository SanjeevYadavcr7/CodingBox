#include<bits/stdc++.h>
using namespace std;

int getPossibleCoinComb(int coins[], int n, int total_amt){
	vector<int> dp(total_amt+1,0);
	// dp[i] => no. possible combinations of coins to get 'i' amount
	dp[0] = 1;
	for(int i=0;i<n;i++){
		int curr_coin = coins[i];
		
		for(int curr_amt = 1 ; curr_amt <= total_amt; curr_amt++){
			if(curr_amt >= curr_coin){
				int left_amt = curr_amt - curr_coin;
				dp[curr_amt] += dp[left_amt]; 
			}
		}
	}
	return dp[total_amt];
}

int main(){
	int n;
	cin>>n;
	int coins[n];
	for(int i=0;i<n;i++) cin>>coins[i];
	
	int amt;
	cin>>amt;
	
	int poss_coin_comb = getPossibleCoinComb(coins,n,amt); 
	cout<<poss_coin_comb<<"\n";
	
	return 0;
}





// NOTE : we are only getting possible combinantions(*not permutation) in answer because we are taking each coin 
// once(same order as in coins[])
// so for eg. coins[] = {2,3,5}   target amount = 7
// answer is all possible coins combinations of target amount = (2,2,3) (2,5)
// not all possible permutaions = (2,2,3)  (2,3,2)  (3,2,2)  (2,5)  (5,2)
