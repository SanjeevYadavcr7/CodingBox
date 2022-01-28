#include<bits/stdc++.h>
using namespace std;

string getUniqueLetters(string str,unordered_map<char,int>& mp){
	string word = "";
	for(char ch : str){
		if(mp.find(ch) == mp.end()){
			mp[ch] = -1;
			word += ch;
		}
	}	
	return word;
}

int getNum(unordered_map<char, int>& mp, string str){
	int num = 0;
	for(char ch : str) num = num*10 + mp[ch];
	return num;
}

bool solve(string word, int idx, unordered_map<char,int>& mp, vector<bool>& isTaken, vector<string>& words, string result){
	if(idx == word.size()){
		int total = 0;
		for(string str : words) total += getNum(mp,str);
		int res = getNum(mp,result);
		if(total == res) return true;
		return false;
	}
	
	for(int i=0; i<=9; i++){
		if(!isTaken[i]){
			char ch = word[idx];
			isTaken[i] = true;
			mp[ch] = i;
			bool ans = solve(word,idx+1,mp,isTaken,words,result);
			if(ans) return true;
			isTaken[i] = false;
			mp[ch] = -1;
		}
	}
	return false;
}

bool isSolvable(vector<string>& words, string result){
	vector<bool> isTaken(10,false);
	unordered_map<char,int> mp;
	string word = "";
	for(string str : words) word += getUniqueLetters(str,mp);
	word += getUniqueLetters(result,mp);
	
	if(solve(word,0,mp,isTaken,words,result)) return true;
	return false;
}

int main(){
	int n;
	cin >> n;
	vector<string> words(n);
	for(int i=0; i<n; i++) cin >> words[i];
	
	string result;
	cin >> result;
	
	if(isSolvable(words,result)) cout << "true";
	else cout << "false";
	cout << "\n";


	return 0;
}
