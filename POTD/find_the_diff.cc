#include<bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t) {
    char ch;
    unordered_map<char,int> mp;
    for(char ch : s) mp[ch] += 1;
    for(char ch : t) mp[ch] -= 1;
    for(auto it : mp){
        if(it.second != 0){
            ch = it.first;
            break;
        }
    }
    return ch;
}

int main(){
    string s,t;
    cin >> s;
    cin >> t;

    char ch = findTheDifference(s,t);
    cout << ch << "\n";

    return 0;
}