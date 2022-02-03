#include<bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
	int tar = 0, cnt = 0, n = nums1.size();
	unordered_map<int,int> mp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int sum = nums3[i] + nums4[j];
			//cout << sum << " ";
			mp[sum] += 1;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int sum = nums1[i] + nums2[j];
			if(mp[tar-sum]){
				//cout << "\n" << nums1[i] << " " << nums2[j] << "| " << tar-sum;
				cnt += mp[tar-sum];
			} 
		}
	}
	//cout<< "\n";
	return cnt;	
}

int main(){
	int n;
	cin >> n;
	vector<int> arr1(n,0),arr2(n,0),arr3(n,0),arr4(n,0);
	for(int i=0; i<n; i++) cin >> arr1[i];
	for(int i=0; i<n; i++) cin >> arr2[i];
	for(int i=0; i<n; i++) cin >> arr3[i];
	for(int i=0; i<n; i++) cin >> arr4[i];
	
	int ans = fourSumCount(arr1,arr2,arr3,arr4);
	cout << ans << "\n";
	
	return 0;
}
