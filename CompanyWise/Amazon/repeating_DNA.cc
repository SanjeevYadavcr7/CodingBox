#include<bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {    
    int n = s.length(), k = 10;
    vector<string> ans;
    unordered_map<string,int> mp;
    for(int i=0; i<=n-k; i++){
        string str = s.substr(i,k);
        mp[str]++;
    }
    for(auto it : mp){
        if(it.second > 1) ans.push_back(it.first);
    } 
    return ans;
}

int main(){ 
    string str;
    getline(cin, str);

    vector<string> arr = findRepeatedDnaSequences(str);
    for(string s : arr) cout << s << " ";
    cout << "\n";

    return 0;
}