#include<bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones){
	int n = stones.size();
	priority_queue<int> bag;
	
	for(int i=0; i<n; i++) bag.push(stones[i]);
	
	while(bag.size() > 1){
		int x = bag.top(); bag.pop();
		int y = bag.top(); bag.pop();
		if(x != y) bag.push(x-y);
	}
	
	return (bag.empty()) ? 0 : bag.top();
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n); 
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int ans = lastStoneWeight(arr);
	cout << ans << "\n";
	
	return 0;
}
