#include<bits/stdc++.h>
using namespace std;

int minimumDeviation(vector<int>& nums){
	priority_queue<int> max_heap;
	int min_val = INT_MAX, max_val = INT_MIN;

	for(int &i : nums){
		int curr_val = i;
		if(curr_val & 1) curr_val *= 2;
		max_heap.push(curr_val);
		min_val = min(min_val,curr_val);
	}	

	int diff = INT_MAX;
	while(!(max_heap.top()&1)){
		int curr_val = max_heap.top();
		max_heap.pop();
		diff = min(diff,curr_val - min_val);
		
		int new_val = curr_val/2;
		max_heap.push(new_val);
		min_val = min(min_val,new_val);
	}

	int min_dev = min(diff,max_heap.top() - min_val);
	return min_dev;
}

int main(){
	int n;
	cin >> n;
	vector<int> nums(n,0);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	int min_dev = minimumDeviation(nums);
	cout << min_dev << "\n";
	
	return 0;
}
