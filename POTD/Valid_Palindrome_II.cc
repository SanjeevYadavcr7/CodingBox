#include<bits/stdc++.h>
using namespace std;

/*
bool isPalidrome(string str, int idx){
	int n = str.size();
	int i = 0, j = n-1;
	
	while(i < j){
		if(i == idx) i++;
		if(j == idx) j--;
		if(str[i] != str[j]) return false;
		i++, j--;
	}
	return true;
};

bool validPalindrome(string s){
	int n = s.size();
	int i = 0, j = n-1;
	
	while(i < j){
		if(s[i] != s[j]) break;
		i++, j--;
	}	
	return isPalidrome(s,i) || isPalidrome(s,j);
}
*/
	
int main(){	
	string str;
	cin >> str;
	
	if(validPalindrome(str)) cout << "true\n";
	else cout << "false\n";

	return 0;
}



