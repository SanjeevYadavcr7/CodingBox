#include<bits/stdc++.h>
using namespace std;

string reverseStr(string str){
	int n = str.size();
	for(int i=0; i<n/2; i++){
		char ch = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = ch;
	}
	return str;
}

void getPalinPermutations(int idx, int len, unordered_map<char,int>& mp, string psf, char odd, vector<string>& ans){
	if(idx > len){ 
		string str = psf;
		if(odd != ' ') str += odd;
		str += reverseStr(psf);		
		ans.push_back(str);
		return;
	}
	
	for(auto it : mp){
		int freq = it.second;
		if(freq > 0){
			char curr_ch = it.first;
			mp[curr_ch] -= 1;
			getPalinPermutations(idx+1,len,mp,psf+curr_ch,odd,ans);	
			mp[curr_ch] += 1;
		}
	}
}


vector<string> all_plaindromes(string str){
	vector<string> ans;
	unordered_map<char,int> mp;
	
	for(char ch : str) mp[ch] += 1;
	
	char odd = ' '; int len = 0, odds = 0;
	for(auto it : mp){
		int freq = it.second;
		char ch = it.first;
		if(freq & 1){
			odd = ch;
			odds++;
		}  
		mp[ch] = freq/2;
		len += freq/2;
	}
	
	if(odds > 1) return ans;
	
	getPalinPermutations(1,len,mp,"",odd,ans);
	sort(ans.begin(),ans.end());
	return ans;
}

int main(){
	string str;
	cin >> str;
	
	vector<string> ans = all_plaindromes(str);
	for(string str : ans) cout << str << " ";
	cout << "\n";

	return 0;
}
