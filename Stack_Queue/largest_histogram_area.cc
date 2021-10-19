#include<bits/stdc++.h>
using namespace std;

vector<int> getLeftSmallestIndex(int arr[], int n){
	
	vector<int> ans(n);
	stack<int> s;
	
	ans[0] = -1;
	s.push(0);
	
	for(int i=1;i<n;i++){
		while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
		if(s.empty()) ans[i] = -1;
		else ans[i] = s.top();
		s.push(i);
	}
	return ans;	
}

vector<int> getRightSmallestIndex(int arr[], int n){
	
	vector<int> ans(n);
	stack<int> s;
	
	ans[n-1] = n;
	s.push(n-1);
	
	for(int i=n-2;i>=0;i--){
		while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
		if(s.empty()) ans[i] = n;
		else ans[i] = s.top();
		s.push(i);
	}
	return ans;
}


int getLargestArea(int arr[], int n){
	
	vector<int> lsi = getLeftSmallestIndex(arr,n);
	vector<int> rsi = getRightSmallestIndex(arr,n);
	
	
	int maxArea = 0;
	for(int i=0;i<n;i++){
		int w = rsi[i]-lsi[i]-1;
		int area = w*arr[i];
		maxArea = max(maxArea, area);
	}
	return maxArea;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int area = getLargestArea(arr,n);
	cout<<area<<endl;
	
	return 0;
}
