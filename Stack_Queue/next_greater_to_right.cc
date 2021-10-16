#include<bits/stdc++.h>
using namespace std;

void nextGreater(int arr[], int n){
	
	vector<int> ans;
	
	stack<int> stk;
	stk.push(arr[n-1]);
	ans.push_back(-1);	
	
	for(int i=n-2;i>=0;i--){
		if(arr[i] > stk.top()){
			while(!stk.empty() && arr[i] >= stk.top()) stk.pop();	
			if(stk.empty()) ans.push_back(-1);
			else ans.push_back(stk.top());	
			stk.push(arr[i]);
		}
		else{
			ans.push_back(stk.top());
			stk.push(arr[i]);
		} 
	}
	for(int i=n-1;i>=0;i--) cout<<ans[i]<<" ";
	cout<<endl;
}

int main(){	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	nextGreater(arr, n);
	
	return 0;
}
