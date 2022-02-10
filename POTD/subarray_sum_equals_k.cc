#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& arr, int k){
	int n = arr.size();
	int curr_sum = 0,cnt=0;
    unordered_map<int,int> mp;
        
    for(int i=0;i<n;i++){
    	curr_sum += arr[i];
            
        if(curr_sum == s) cnt += 1;
        cnt+=mp[curr_sum-s];
        
        mp[curr_sum] += 1;
    }
	return cnt;
}

int main(){
	int n,k;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	cin >> k;
	
	int k_sum_subarray = subarraySum(arr,k);
	cout << k_sum_subarray << "\n";
	
	return 0;
}

