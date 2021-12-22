#include<bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int a[], int n, int k){
	long long int ans = 0,temp=k;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i] < 0){
			a[i] *= -1;
			k--;
			if(k == 0) break; 
		}
		else break;
	}   
	
	sort(a,a+n);
	
	cout<<"arr[] = ";
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	
	for(int i=1;i<n;i++) ans += a[i];
	if(k == 0 || k%2 == 0) return a[0]+ans;
	return ans-a[0];		
}

int main(){
	
	int n,k;
	cin>>n;
	long long int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	cin>>k;
	long long int ans = maximizeSum(arr,n,k);
	cout<<ans<<endl;
	
	return 0;
}
