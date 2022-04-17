#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

int threeSumMulti(vector<int>& nums, int target){
	int n = nums.size();
	int res = 0;
	
	sort(nums.begin(),nums.end());
	for(int x=0; x<n; x++){
		int y = x+1, z = n-1;
		while(y < z){
			int sum = nums[x] + nums[y] + nums[z];
			if(sum == target){
				int y_freq = 1, z_freq = 1;
				while(y<z && nums[y] == nums[y+1]){
					y_freq++;
					y++;
				}
				while(y<z && nums[z] == nums[z-1]){
					z_freq++;
					z--;
				}
				
				if(y != z){
					int ways = ((y_freq % M) * (z_freq % M)) % M;
					res += ways;
					res %= M;
				}
				else{
					int ways = ((y_freq % M) * ((y_freq-1)%M)/2) % M;
					res += ways;
					res %= M;
				}
				y++;
				z--;
			}
			else if(sum < target) y++;
			else z--;
		}
	}
	return res;
}

int main(){
	int n,tar;
	cin >> n >> tar;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int ans = threeSumMulti(arr,tar);
	cout << ans << "\n";
	
	return 0;
}
