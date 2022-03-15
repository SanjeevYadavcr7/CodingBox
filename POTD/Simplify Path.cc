#include<bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------------------------------------
Type: Sub-Optimal
Approach 1: Generating array of splitted words | using stack to parse splitted words
			Complexities -  Time: O(n+m) | Space: O(m+m)
			n = path.size()
			m = number of splitted words 
-------------------------------------------------------------------------------------

vector<string> getSplittedPath(string path){
	vector<string> ans;
	int n = path.size();
	string word = "";
	
	for(int i=0; i<n; i++){
		if(path[i] == '/'){
			ans.push_back(word);
			word = "";
		}
		else word += path[i];
	}
	if(word != "/") ans.push_back(word);
	return ans;
}

string simplifyPath(string path){
	vector<string> splitted_path = getSplittedPath(path);  
	string str = "";
	stack<string> stk;
	
	for(string word : splitted_path){
		if(word == "") continue;	
		else if(word == ".."){
			if(!stk.empty()) stk.pop();
		}
		else if(word == ".") continue;
		else stk.push(word);
	}
	
	if(stk.empty()) return "/";
	
	while(!stk.empty()){
		str = "/" + stk.top() + str;
		stk.pop();
	}
	return str;
}
*/




/*
----------------------------------------------------------------------------------
Type: Optimal
Approach 2: Not using extra array to store splitted words but using them on the go
			Complexities- Time: O(n)  |  Space: O(n)
----------------------------------------------------------------------------------
*/
string simplifyPath(string path){
	int n = path.size();
	stack<string> stk;
	string ans = "";
	
	for(int i=0; i<n; i++){
		if(path[i] == '/') continue;
		string word = "";
		while(i<n && path[i] != '/') word += path[i++s];
		
		if(word == ".") continue;
		else if(word == ".."){
			if(!stk.empty()) stk.pop();
		} 
		else stk.push(word);
	}
	
	if(stk.empty()) return "/";
	while(!stk.empty()){
		ans = "/" + stk.top() + ans;
		stk.pop();
	}
	return ans;
}

int main(){
	string path;
	cin >> path;
	
	string canonical_path = simplifyPath(path);
	cout << canonical_path << "\n";
	
	return 0;
}
