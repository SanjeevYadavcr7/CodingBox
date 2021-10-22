#include<bits/stdc++.h>
using namespace std;

void getMergedIntervals(vector<pair<int,int>> arr, int n){
	
	sort(arr.begin(), arr.end());
	stack<pair<int,int>> stk, ans;
	stk.push({arr[0].first, arr[0].second});
	
	for(int i=1;i<n;i++){
		if(arr[i].first <= stk.top().second){
			if(arr[i].second > stk.top().second) stk.top().second = arr[i].second;
		}
		else{
			stk.push({arr[i].first, arr[i].second});
		}
	}	
	
	while(!stk.empty()){
		ans.push({stk.top().first, stk.top().second});
		stk.pop();
	}
	
	while(!ans.empty()){
		cout<<ans.top().first<<" "<<ans.top().second<<endl;
		ans.pop(); 
	}
}

int main(){
	int n,s,e;
	cin>>n;
	vector<pair<int,int>> arr;
	for(int i=0;i<n;i++){
		cin>>s>>e;
		arr.push_back({s,e});
	}
	getMergedIntervals(arr,n);
	return 0;
}
