#include<bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
        int max_coin = *max_element(nums.begin(),nums.end());
        vector<int> coin_freq(max_coin+1,0);
        vector<int> earning(max_coin+1);
        
        for(int &i : nums) coin_freq[i] += 1;
        earning[0] = 0;
        earning[1] = coin_freq[1];
        
        
        for(int coin = 2; coin <=max_coin; coin++){
            int curr_coin_earning = coin * coin_freq[coin];
            int max_earning = max(earning[coin-1], earning[coin-2]+curr_coin_earning);
            earning[coin] = max_earning;
        }
        return earning[max_coin];
    }

int deleteAndEarn(vector<int>& nums) {
    int total = 0;
    map<int,int> mp;
        
    for(int i : nums){
        total += i;
        mp[i] += 1;
    }    
    int n = mp.size(), i = 0, ans = 0;
    vector<pair<int,int>> earn(n);
    auto it = mp.begin();
    earn[i] = {it->first,(it->first*it->second)};
    ans = it->first*it->second;
    it++;
    i++;

    for(;it != mp.end(); it++){
        int curr = it->first;
        int freq = it->second;
        int max_earn = 0;
        for(int j=i-1; j>=0; j--){
            auto prev = earn[j];
            if(prev.first+1 == curr) continue;
            max_earn = max(max_earn,prev.second);
        }
        max_earn += (freq*curr);
        ans = max(max_earn,ans);
        earn[i] = {curr,max_earn};
        i++;
    }
    return ans;
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++) cin >> arr[i];
    
    int max_earn = deleteAndEarn(arr);
    cout << max_earn << "\n";
 
    return 0;
}