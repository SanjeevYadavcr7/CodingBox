#include<bits/stdc++.h>
using namespace std;

int minCoinsHelper(int arr[], int n,int curr_amt, int tar_amt, vector<int>& mem){
    	if(curr_amt > tar_amt) return INT_MAX;
    	if(curr_amt == tar_amt) return 1;
    	
    	if(mem[curr_amt]) return mem[curr_amt];
    	
    	int min_coins = INT_MAX;
    	for(int i=0;i<n;i++){
    		int new_amt = curr_amt + arr[i];
    		int coins = minCoinsHelper(arr,n,new_amt,tar_amt,mem);
    		if(coins) min_coins = min(min_coins,coins);	
    	}
    	if(min_coins != INT_MAX) mem[curr_amt] = min_coins+1;
    	else mem[curr_amt] = 0;
    	
    	return mem[curr_amt];
}
    
int minCoins(int arr[], int n,int tar_amt){
    	vector<int> mem(n+1,0);
    	int min_coins = minCoinsHelper(arr,n,0,tar_amt,mem);
    	return min_coins;
}

int main(){
	int v,n;
	cin>>v>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int min_coins = minCoins(arr,n,v);
	cout<<min_coins<<"\n";

	return 0;
}
