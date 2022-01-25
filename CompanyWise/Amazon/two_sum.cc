#include<bits/stdc++.h>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            //if(target >= nums[i]){
                int req = target - nums[i];
                if(mp[req] > 0){
                    ans.push_back(mp[req]-1);
                    ans.push_back(i);
                }
                mp[nums[i]] = i+1;
            //}
        }
        
        return ans;
    }

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> ans = twoSum(arr,k);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}