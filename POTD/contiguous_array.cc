#include<bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums){
	int n = nums.size();
	 
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int max_len = findMaxLength(arr);
	cout << max_len << "\n";

	return 0;
}
