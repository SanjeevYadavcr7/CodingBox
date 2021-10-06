#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int x, int beg, int end){
		if(end>=beg){
			int mid = beg+(end-beg)/2;
			if(arr[mid] == x) return mid;
			else if(arr[mid] > x) return binary_search(arr, x, beg, mid-1);
			else return binary_search(arr, x, mid+1, end);
		}	
		return -1;
}

int main(){
	int n;
	cin>>n;
	if(n == 1){
		int n = 8;
	}
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int x;
	cin>>x;
	if(binary_search(arr,x,0,n-1) == -1) cout<<"not present!\n";
	else cout<<"present at position "<<binary_search(arr,x,0,n-1)<<"\n";
	
	return 0;
}
