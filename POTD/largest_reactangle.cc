#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& arr){
	int n = arr.size(), i = 1;
	vector<int> left(n), right(n);
	stack<int> stk;
	
	stk.push(0);
	left[0] = 0;
	while(i<n && !stk.empty()){
		if(arr[i] <= arr[stk.top()]){
			while(!stk.empty() && arr[i] <= arr[stk.top()]) stk.pop();
			if(stk.empty()) left[i] = 0;
			else left[i] = stk.top()+1; 
		}
		else{
			left[i] = i;
		}
		stk.push(i);
		i++;
	}
	
	i = n-2;
	right[n-1] = n-1;
	stk = stack<int>();
	stk.push(n-1);
	while(i>=0 && !stk.empty()){
		if(arr[i] <= arr[stk.top()]){
			while(!stk.empty() && arr[i] <= arr[stk.top()]) stk.pop();
			if(stk.empty()) right[i] = n-1;
			else right[i] = stk.top()-1; 
		}
		else{
			right[i] = i;
		}
		stk.push(i);
		i--;
	}
	
	int max_area = INT_MIN;
	for(int i=0; i<n; i++){
		int area = (right[i]-left[i]+1)*arr[i];
		max_area = max(max_area,area);
	}
	
	return max_area;
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int area = largestRectangleArea(arr);
	cout << area << "\n";

	return 0;
}
