#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> triplets;
    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int a = nums[i];
        int l = i+1, r = n-1;
        while(l<r){
            int three_sum = a + nums[l] + nums[r];
            if(three_sum == 0){
                triplets.push_back({nums[i], nums[l], nums[r]});
                l++; 
                while(l < r && nums[l-1] == nums[l]) l++;
            }            
            else if(three_sum < 0) l++;
            else r--;
        }
    }

    return triplets;
} 

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i=0; i<n; i++) cin >> nums[i];
    
    vector<vector<int>> ans = threeSum(nums);
    for(auto i : ans){
        cout << "(";
        for(int j : i){
            cout << j << " ";
        }
        cout << ") ";
    }
    cout << "\n";

    return 0;
}