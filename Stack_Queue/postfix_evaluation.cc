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
	stack<string> prefix;
	stack<int> val;
	
	for(char ch:str){
		if(isdigit(ch)){
			int num = ch - '0';
			val.push(num);
			string temp = "";
			temp += ch;
			infix.push(temp);
			prefix.push(temp);
		}
		else{
			int v2 = val.top();
			val.pop();
			int v1 = val.top();
			val.pop();			
			int res = getValue(v1,v2,ch);
			val.push(res);
			
			
			string p2 = infix.top();
			infix.pop();
			string p1 = infix.top();
			infix.pop();
			string infix_res = "("+p1+ch+p2+")";
			infix.push(infix_res);
			
			p2 = prefix.top();
			prefix.pop();
			p1 = prefix.top();
			prefix.pop();
			string prefix_res = ch+p1+p2;
			prefix.push(prefix_res);					
		}
	}
	cout<<val.top()<<endl;
	cout<<infix.top()<<endl;
	cout<<prefix.top()<<endl;
}

int main(){
	string str;
	getline(cin, str);
	solve(str);
	return 0;
}

