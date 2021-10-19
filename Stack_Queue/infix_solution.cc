#include<bits/stdc++.h>
using namespace std;

int precedence(char x){
	if(x == '+') return 1;
	else if(x == '-') return 1;
	else if(x == '*') return 2;
	else if(x == '/')return 2;
	return 0;
}

int solve(int a, int b, char op){
	if(op == '+') return a+b;
	else if(op == '-') return a-b;
	else if(op == '*') return a*b;
	else return a/b;
	return 0;
}

void solve(string str){

	stack<char> operators;
	stack<int> operands;
	
	for(char ch : str){
		// cout<<"Current character = "<<ch<<endl;
		if(isdigit(ch)) {
			int num = ch - '0';
			operands.push(num);
		}
		else if(ch == ' ')continue;
		else{
			if(ch == '(') operators.push(ch);
			else if(ch == ')'){
				while(!operators.empty() && operators.top() != '('){
					int b = operands.top();
					operands.pop();
					int a = operands.top();
					operands.pop();
					char op = operators.top();
					operators.pop();
					int res = solve(a,b,op);
					operands.push(res);
				}
				operators.pop();
			}
			else {
				// cout<<"Calculating "<<ch<<"\n";
				while(!operators.empty() && precedence(operators.top()) >= precedence(ch)){
					int b = operands.top();
					operands.pop();
					int a = operands.top();
					operands.pop();
					char op = operators.top();
					operators.pop();
					int res = solve(a,b,op);
					// cout<<"a="<<a<<" "<<op<<" "<<"b="<<b<<" ==> result = "<<res<<endl;
					operands.push(res);
				}
				operators.push(ch);
			}
		}
	}
	
	while(!operators.empty()){
		int b = operands.top();
		operands.pop();
		int a = operands.top();
		operands.pop();
		char op = operators.top();
		operators.pop();
		int res = solve(a,b,op);
		operands.push(res);
	}
	cout<<operands.top()<<endl;	
}

int main(){
	string str;
	getline(cin, str);
	solve(str);
	return 0;
}
