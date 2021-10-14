#include<bits/stdc++.h>
using namespace std;

void printTargetSumSubsets(vector<int> arr, int idx, string temp, int sos, int tar, int n){
	
	if(sos > tar) return;
     
	if(idx == n){
		if(sos == tar) cout<<temp<<".\n";
		return;
	}
	
	printTargetSumSubsets(arr, idx+1, temp+to_string(arr[idx])+", ", sos+arr[idx], tar, n);
	printTargetSumSubsets(arr, idx+1, temp, sos, tar, n);
}

int main(){
	int n,x,tar;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		cin>>x;
		arr.push_back(x);
	}
	cin>>tar;

	printTargetSumSubsets(arr,0,"",0,tar, n);
	
	return 0;
}
