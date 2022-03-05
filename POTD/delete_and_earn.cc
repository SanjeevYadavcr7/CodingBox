#include<bits/stdc++.h>
using namespace std;

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