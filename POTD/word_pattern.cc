#include<bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s){
	int n = pattern.length(), m;
	bool res = true;
	vector<string> str;
	
	stringstream ss(s);
	string word;
	while(ss >> word) str.push_back(word);
	
	m = str.size();
	if(n != m) return false;
	
	unordered_map<char, string> char_map;
	unordered_map<string, bool> string_map;
	for(int i=0; i<n; i++){
		char curr_ch = pattern[i];
		string curr_str = str[i];
		if(!string_map[curr_str]){
			if(char_map[curr_ch].length() > 0 && (char_map[curr_ch] != curr_str)) return false;
			char_map[curr_ch] = curr_str;
			string_map[curr_str] = true;
		}
		else{
			if(char_map[curr_ch] != curr_str) return false;
		}
	}
	
	return res;
}

int main(){
	string pattern, str;
	getline(cin,pattern);
	getline(cin,str);
	
	if(wordPattern(pattern, str)) cout << "true";
	else cout << "false";
	cout << "\n";

	return 0;
}
