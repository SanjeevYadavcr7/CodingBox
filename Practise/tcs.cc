#include<iostream>
using namespace std;

int solve(int arr[], int n, int y){
	int ans = 0;
	ans = arr[0]+arr[n-1];
	int cnt = 0;
	for(int i=1;i<n-1;i++){
		if(arr[i] > y && cnt < 2){
			ans += y;
			cnt++;
		}
		else{
			ans += arr[i];
			cnt = 0;
		} 
	}
	return ans;
}

int main(){
	int n,y;
	cin >>n >> y;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int res = solve(arr, n, y);
	cout<<res<<endl; 

	return 0;
}

