#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int arr[], int n){
	
	int ans1=0, ans2=0, d1, d2;
	int m = INT_MAX;
	
	sort(arr, arr+n);
	
	int l=1, r=n-2;
	
	if(n == 2) return 0;
	else if(n == 3){
		int ans = min(arr[1]-arr[0], arr[2]-arr[1]);
		return ans;
	}
	for(int i=0;i<n-1;i++) ans1 += abs(arr[i] - arr[(n-1)/2]);
	for(int i=1;i<n;i++) ans2 += abs(arr[i] - arr[1+(n-1)/2]);
	m = min(ans1, ans2);
	while(l<r){
		d2 = arr[n-1] - arr[l];
		d1 = arr[r] - arr[0];
		m = min(m, abs(d1-d2));
		if(d1 < d2) l++;
		else r--;
	}
	return m;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		cout<<solve(arr,n)<<endl;
	}
	return 0;
}
