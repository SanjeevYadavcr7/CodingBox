#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterLeft(int arr[], int n){
	
	vector<int> ans;
	
	stack<int> stk;
	stk.push(0);
	ans.push_back(-1);
	for(int i=1;i<n;i++){
		if(arr[i] > arr[stk.top()]){
			while(!stk.empty() && arr[i] > arr[stk.top()]) stk.pop();
			if(stk.empty()) ans.push_back(-1);
			else ans.push_back(stk.top());
			stk.push(i);
		}
		else{
			ans.push_back(stk.top());
			stk.push(i);
		}
	}
	
	return ans;
}

void getStockSpan(int arr[],int n){
	vector<int> ans = nextGreaterLeft(arr,n);
	for(int i=0;i<n;i++) cout<<i-ans[i]<<"\n";
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	getStockSpan(arr,n);
	
	return 0;
}

