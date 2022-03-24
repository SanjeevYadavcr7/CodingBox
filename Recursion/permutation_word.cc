#include<bits/stdc++.h>
using namespace std;

void permute(int idx, int n, map<char,int>& mp, string psf){
	if(idx == n){
		cout << psf << "\n";
		return;
	}
	
	for(auto i : mp){
		int freq = i.second;
		if(freq > 0){
			char ch = i.first;
			mp[ch] -= 1;
			permute(idx+1,n,mp,psf+ch);
			mp[ch] += 1;
		}
	}
}

void wordPermutation(string word){
	int n = word.size();
	map<char,int> mp;
	for(char ch : word) mp[ch] += 1;
	permute(0,n,mp,"");
}

int main(){
	string str;
	cin >> str;
	wordPermutation(str);
	return 0;
}
