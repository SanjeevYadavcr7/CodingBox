#include<bits/stdc++.h>
using namespace std;

bool validPalindrome(string s){
	int n = s.size();
	int i = 0, j = n-1;
	int cnt = 1;
	
	while(i < j){
		if(s[i] != s[j]){
			if(cnt > 0){
				if(s[i] == s[j-1]) j--, cnt--;
				else if(s[i+1] == s[j]) i++, cnt--;
				else return false;
			}
			else return false;
		}
		else i++, j--;
	}
	return true;
}

int main(){	
	string str;
	cin >> str;
	
	if(validPalindrome(str)) cout << "true\n";
	else cout << "false\n";

	return 0;
}
