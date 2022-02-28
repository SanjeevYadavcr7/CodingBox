#include<bits/stdc++.h>
using namespace std;

void display(unordered_map<char,string>& mp, string str){
	int n = str.size();
	unordered_map<char,bool> vis;
	
	for(int i=0; i<n; i++){
		char ch = str[i];
		if(!vis[ch]){
			cout << ch << " -> " << mp[ch] << ", ";
			vis[ch] = true;
		}
	}
	cout << ".\n";
}

void patternMatching(int idx, string pattern, string str, unordered_map<char,string>& mp){
	
	if(idx == pattern.size()){
		if(str.size() == 0) display(mp,pattern);
		return;
	}
	
	char ch = pattern[idx];
	if(mp.find(ch) != mp.end()){
		string prev = mp[ch];
		int n = prev.size();
		if(str.size() >= n){
			string left = str.substr(0,n);
			string right = str.substr(n);
			if(left == prev) patternMatching(idx+1,pattern,right,mp);
		}
	}
	else{
		for(int i=0; i<str.size(); i++){
			string left = str.substr(0,i+1);
			string right = str.substr(i+1);
			mp[ch] = left;
			patternMatching(idx+1,pattern,right,mp);
			mp.erase(ch);
		}
	}
}

int main(){
	string str, pattern;
	cin >> str;
	cin >> pattern; 
	
	unordered_map<char,string> mp;
	patternMatching(0,pattern,str,mp);
	return 0;
}
