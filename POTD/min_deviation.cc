#include<bits/stdc++.h>
using namespace std;

int minimumDeviation(vector<int>& nums){
        
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
