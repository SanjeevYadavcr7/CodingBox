#include<bits/stdc++.h>
using namespace std;

bool binary_search(int beg, int end, int tar, vector<int>& arr){
	while(beg <= end){
    	int mid = (end-beg)/2 + beg;
        if(arr[mid] == tar) return true;
        else if(arr[mid] < tar) beg = mid+1;
        else end = mid - 1;
    }
    return false;
}
    
bool search(vector<int>& nums, int target) {
	int n = nums.size();
    int beg = 0, end = n-1;
        
    int i = 1;
    while(i<n && nums[i] >= nums[i-1]) i++;
        
    return binary_search(beg,i-1,target,nums) || binary_search(i,end,target,nums);
}

int main(){
	int n,tar;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	cin >> tar;

	if(search(arr,tar)) cout << "true\n";
	else cout << "false\n";
	 
	return 0;
}
