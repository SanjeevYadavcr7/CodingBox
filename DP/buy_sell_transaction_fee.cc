#include<bits/stdc++.h>
using namespace std;

void doTransactions(int arr[], int n, int fee){
	int bsp = -arr[0];
	int ssp = 0;
	for(int i=1;i<n;i++){
		int new_bsp = ssp - arr[i];
		int new_ssp = arr[i] + bsp - fee;
		ssp = max(ssp,new_ssp); 
		bsp = max(bsp,new_bsp);
	}
	cout << ssp << "\n";
}

int main(){	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int fee;
	cin>>fee;
	
	doTransactions(arr,n,fee);
	
	return 0;
}
