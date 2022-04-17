#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height){
	int n = height.size();
	int left = 0, right = n-1;
	int max_area = 0;
	
	while(left < right){
		int curr_area = min(height[left],height[right]) * (right - left);
		max_area = max(max_area,curr_area);
		
		if(height[left] < height[right]) left++;
		else right--;
	}
	return max_area;
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int area = maxArea(arr);
	cout << area << "\n";
	
	return 0;
}
