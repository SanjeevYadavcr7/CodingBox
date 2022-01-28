#include<bits/stdc++.h>
using namespace std;
void display(unordered_map<char,int>& mp);
string getUniqueLetters(string str,unordered_map<char,int>& mp);


int getNum(unordered_map<char, int>& mp, string str){
	int num = 0;
	for(char ch : str) num = num*10 + mp[ch];
	return num;
}

void solution(string unique, int idx, unordered_map<char,int>& mp, vector<bool>& usedNum, string x, string y, string z){
	if(idx == unique.length()){
		int num1 = getNum(mp,x);
		int num2 = getNum(mp,y);
		int num3 = getNum(mp,z);
		if(num1 + num2 == num3) display(mp);
		return;
	}
	
	for(int i=0; i<=9; i++){
		if(!usedNum[i]){	
			usedNum[i] = true;
			char curr_char = unique[idx];
			mp[curr_char] = i;
			solution(unique,idx+1,mp,usedNum,x,y,z);	
			usedNum[i] = false;
			mp[curr_char] = -1;
		}
	}
}

int main(){
	string x,y,z;
	getline(cin,x);
	getline(cin,y);
	getline(cin,z);
	
	unordered_map<char,int> mp;
	string unique = getUniqueLetters(x,mp) + getUniqueLetters(y,mp) + getUniqueLetters(z,mp); 
	vector<bool> usedNum(10,false);
	
	solution(unique,0,mp,usedNum,x,y,z);
	/*
	map<char,int> new_mp;
	new_mp['a'] = 3;
	new_mp['e'] = 9;
	new_mp['m'] = 4;
	new_mp['o'] = 1;
	new_mp['p'] = 2;
	new_mp['r'] = 6;
	new_mp['t'] = 0;
	if(checkWordsSum(new_mp,x,y,z)) display(new_mp);
	*/
	
	return 0;
}






































void display(unordered_map<char,int>& mp){
	for(int i=0; i<26; i++){
		char curr_ch = 'a'+i;
		if(mp.find(curr_ch) != mp.end()) cout << curr_ch << "-" << mp[curr_ch] << " ";
	}
	cout << "\n";
}

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

