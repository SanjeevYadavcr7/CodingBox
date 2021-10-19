#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n, int k){
	
	int nge[n];
	stack<int> s;
	
	s.push(n-1);
	nge[n-1] = n;
	for(int i=n-2;i>=0;i--){
		while(!s.empty() && arr[i] >= arr[s.top()]) s.pop();
		if(s.empty()) nge[i] = n;
		else nge[i] = s.top();
		s.push(i);
	}
	
	int j = 0;
	for(int i = 0; i <= n-k ; i++){
		if(j<i) j=i;
		while(nge[j] < i+k) j = nge[j];
		cout<<arr[j]<<"\n";
	}	
	cout<<endl;
}

int main(){
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	cin>>k;
	
	solve(arr,n,k);
	
	return 0;
}
