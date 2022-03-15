#include<bits/stdc++.h>
using namespace std;
 
void countDistinctSubsSeq(string str){
    int n = str.size();
    vector<int> dp(n+1);
    unordered_map<char,int> mp;

    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = 2 * dp[i-1];
        char ch = str[i-1];
        int lastOcc = mp[ch];
        if(lastOcc) dp[i] = dp[i] - dp[lastOcc-1];
        mp[ch] = i;
    }
    cout << dp[n]-1 << "\n";
}

int main(){
    string str;
    cin >> str;

    countDistinctSubsSeq(str);
 
    return 0;
}