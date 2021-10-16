#include<bits/stdc++.h>
using namespace std;

bool isExtraBracketPresent(string str){

	stack<char> arr;
	for(int i=0;i<str.length();i++){
		char ch = str[i];		
		if(ch == '(' || (ch >= 'a' && ch <= 'z') || ch == '+') arr.push(ch);
		
		else if(ch == ')'){
			int cnt = 0;
			while(arr.top() != '('){
				cnt++;
				arr.pop();
			} 
			if(cnt > 0) arr.pop();
			else return true;
		}
		else continue;
	}
	return false;
}

int main(){	
	string str;
	getline(cin, str);
	
	if(isExtraBracketPresent(str)) cout<<"true";
	else cout<<"false";
	cout<<endl;
	return 0;
}
