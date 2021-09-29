#include<bits/stdc++.h>
using namespace std;

void stringCompression(string str){
	int n = str.length();
	unordered_map<char, int> mp;
	for(int i=n-1;i>=0;i--){
		char ch = str[i];
		mp[ch] += 1;
	}
	string ans = "";
	for(auto i:mp) ans += i.first;
	cout<<ans<<"\n";
	ans = "";
	for(auto i:mp){
		ans += i.first;
		if(i.second>1) ans += (i.second + '0');
	} 	
	cout<<ans;
}  

int main(){
	string str;
	cin>>str;
	stringCompression(str);
	return 0;
}
