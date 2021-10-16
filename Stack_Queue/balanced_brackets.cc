#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string str){
	
	stack<char> stk;
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		if(ch == '(' || ch == '{' || ch == '[') stk.push(ch);
		else if(ch == ')' || ch == '}' || ch == ']'){
			char ph;
			if(ch == ')') ph = '(';
			else if (ch == '}') ph = '{';
			else ph = '[';
			if(!stk.empty() && ph == stk.top()) stk.pop();
			else return false;
		} 
		else continue;
	}
	if(stk.empty()) return true;
	return false;
}	

int main(){
	string str;
	getline(cin, str);
	
	if(isBalanced(str)) cout<<"true";
	else cout<<"false";
	
	return 0;	
}
