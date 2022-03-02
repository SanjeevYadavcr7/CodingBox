#include<bits/stdc++.h>
using namespace std;

int getMinCharsRemove(string str){
	stack<char> stk;
	for(int i=0; i<str.size(); i++){
		if(stk.empty()) stk.push(str[i]);
		else{
			if(str[i] == '(') stk.push(str[i]);
			else if(str[i] == ')'){
				if(stk.top() == '(') stk.pop();
				else stk.push(str[i]);
			}
		}
	}
	return stk.size();
}

void solve(string str, int rem, unordered_map<string,bool>& mp){
	if(rem == 0){
		if(!mp[str]){
			mp[str] = true;
			if(getMinCharsRemove(str) == 0)cout << str << "\n";
		}
		return;
	}
	
	for(int i=0; i<str.size(); i++){
		string left = str.substr(0,i);
		string right = str.substr(i+1);
		solve(left+right,rem-1,mp);
	}
}

void removeInvalidParenthesis(string str){
	int min_rem = getMinCharsRemove(str);
	unordered_map<string,bool> mp;
	solve(str,min_rem,mp);
}

int main(){
	string str;
	cin >> str;
	
	removeInvalidParenthesis(str);	
	
	return 0;
}
