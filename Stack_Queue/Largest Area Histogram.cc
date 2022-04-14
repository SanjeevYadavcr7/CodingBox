#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>&heights){
	stack<int> stk;
	int n = heights.size();
	int max_area = 0;
	
	for(int i=0; i<n; i++){
		if(stk.empty() || heights[i] >= heights[stk.top()]) stk.push(i);
		else{
			int height = heights[stk.top()];
			stk.pop();
			
			int area = height * (stk.empty() ? i : i - stk.top()-1);
			max_area = max(max_area,area);
			i--;
		}
	}
	
	while(!stk.empty()){
		int height = heights[stk.top()];
		stk.pop();
		
		int area = height * (stk.empty() ? n : n-stk.top()-1);
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
