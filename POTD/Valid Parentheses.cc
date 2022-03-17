#include<bits/stdc++.h>
using namespace std;
  
/*  
	Time : O(n) | Space: O(n)
	
	NOTE: "The solution revolves around validating sub expression to validate whole string"
*/

bool isValidExp(stack<char> stk, char ch){
        if(stk.empty() || (ch == ')' && stk.top() != '(') || (ch == '}' && stk.top() != '{') || (ch == ']' && stk.top() != '[')) return false;
        return true;
}

bool isValid(string s){
	stack<char> stk;
    for(char ch : s){
    	if(ch == '(' || ch == '{' || ch == '[') stk.push(ch);
        else{
        	if(!isValidExp(stk,ch)) return false;
            stk.pop();
        }
	}
    return stk.empty();
}

int main(){
	string str;
	cin >> str;
		
	if(isValid(str)) cout << "true";
	else cout << "false";
	
	return 0;
}
