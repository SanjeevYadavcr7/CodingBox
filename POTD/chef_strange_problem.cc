#include<iostream>
using namespace std;
#define M 1000000007

int solve(int arr[], int n, int x, int m){
	while(m--){
		for(int i=1;i<n;i++) arr[i] = (arr[i]%M + arr[i-1]%M) % M ;
	}
	
	return arr[x-1];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,x,m;
		scanf("%d %d %d",&n,&x,&m);
		
		int arr[n];
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		
		int ans = solve(arr,n,x,m);
		printf("%d\n",ans);
	} 
	
	return 0;
}

