#include<bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pair<char,int>> stk;
        string ans = "";
        
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == '(' || ch == ')'){
                if(!stk.empty() && stk.top().first == '(' && ch == ')') stk.pop();
                else stk.push({ch,i});
            }
        }
        
        if(stk.empty()) return s;
        
        for(int i=n-1; i>=0; i--){
            if(!stk.empty() && i == stk.top().second){
                stk.pop();
                continue;  
            } 
            ans = s[i] + ans;
        }
        return ans;
}

int main(){
	string str;
	cin >> str;
	
	string valid_string = minRemoveToMakeValid(str);
	cout << valid_string << "\n";

	return 0;
}
