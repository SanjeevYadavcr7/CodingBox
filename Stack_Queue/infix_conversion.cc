#include<bits/stdc++.h>
using namespace std;

int precedence(char x){
	if(x == '+') return 1;
	else if(x == '-') return 1;
	else if(x == '*') return 2;
	else if(x == '/')return 2;
	return 0;
}

void convertToPrePost(string str){
	
	stack<string> pre;
	stack<string> post;
	stack<char> op;
	
	for(char ch:str){
		if(isalpha(ch)){
			string temp = "";
			temp += ch;
			pre.push(temp);
			post.push(temp);
		}
		else if(ch == ' ') continue;
		else{
			if(ch == '(') op.push(ch);
			else if(ch == ')'){
				while(!op.empty() && op.top() != '('){
					string v2 = pre.top();
					pre.pop();
					string v1 = pre.top();
					pre.pop();
					string ans = op.top()+v1+v2;
					pre.push(ans);
					
					v2 = post.top();
					post.pop();
					v1 = post.top();
					post.pop();
					ans = v1+v2+op.top();
					post.push(ans);
					
					op.pop();
				}
				op.pop();
			}
			else{
				while(!op.empty() && precedence(op.top()) >= precedence(ch)){
					string v2 = pre.top();
					pre.pop();
					string v1 = pre.top();
					pre.pop();
					string ans = op.top()+v1+v2;
					pre.push(ans);
					
					v2 = post.top();
					post.pop();
					v1 = post.top();
					post.pop();
					ans = v1+v2+op.top();
					post.push(ans);
					
					op.pop();		
				}
				op.push(ch);
			}				
		}
	}
	
	while(!op.empty()){
		string v2 = pre.top();
		pre.pop();
		string v1 = pre.top();
		pre.pop();
		string ans = op.top()+v1+v2;
		pre.push(ans);
		
		v2 = post.top();
		post.pop();
		v1 = post.top();
		post.pop();
		ans = v1+v2+op.top();
		post.push(ans);
		
		op.pop();		
	}
	cout<<post.top()<<endl<<pre.top()<<endl;			
}

int main(){	
	string str;
	getline(cin, str);
	convertToPrePost(str);
	return 0;
}
