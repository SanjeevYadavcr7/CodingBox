#include<bits/stdc++.h>
using namespace std;

int getValue(int n1, int n2, char op){
	if(op == '+') return n1+n2;
	else if(op == '-') return n1-n2;
	else if(op == '*') return n1*n2;
	else return n1/n2;
}

void solve(string str){
	stack<string> infix;
	stack<string> postfix;
	stack<int> value;
	
	for(int i=str.length()-1; i>=0; i--){
		char ch = str[i];
		if(isdigit(ch)){
			int num = ch - '0';
			value.push(num);
			string temp = "";
			temp += ch;
			infix.push(temp);
			postfix.push(temp);
		}
		else{
			int v1 = value.top();
			value.pop();
			int v2 = value.top();
			value.pop();
			int res = getValue(v1,v2,ch);
			value.push(res);
			
			string p1 = infix.top();
			infix.pop();
			string p2 = infix.top();
			infix.pop();
			string infix_res = "("+p1+ch+p2+")";
			infix.push(infix_res);
			
			p1 = postfix.top();
			postfix.pop();
			p2 = postfix.top();
			postfix.pop();
			string postfix_res = p1+p2+ch;
			postfix.push(postfix_res);
		}
	}
	cout<<value.top()<<endl;
	cout<<infix.top()<<endl;
	cout<<postfix.top()<<endl;
}

int main(){
	string str;
	getline(cin,str);
	
	solve(str);
	
	return 0;
}
