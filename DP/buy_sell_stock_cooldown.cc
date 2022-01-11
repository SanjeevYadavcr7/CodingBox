#include<bits/stdc++.h>
using namespace std;

void doTransaction(int arr[], int n){
	int bsp = -arr[0], ssp = 0, csp = 0;
	for(int i=1;i<n;i++){
		int new_bsp = csp - arr[i];
		int new_ssp = arr[i] + bsp;
		bsp = max(bsp,new_bsp);
		csp = max(csp,ssp);
		ssp = max(ssp,new_ssp);
	}
	cout<<ssp<<"\n";
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	doTransaction(arr,n);

	return 0;
}
