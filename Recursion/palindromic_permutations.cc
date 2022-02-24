#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str);
int fact(int n);

set<string> ans;

void getPalindromicPer(int num, int n, string str, string psf){
	if(n == 0){
		if(isPalindrome(psf)) ans.insert(psf);
		return;
	}
	
	int rem = num % n;
	num /= n;
	psf += str[rem];
	string new_str = "";
	for(int i=0; i<str.size(); i++){
		if(i == rem) continue;
		new_str += str[i];
	}
	//cout << "New str = " << new_str << "\n";
	getPalindromicPer(num,n-1,new_str,psf);
}

void solution(string str){
	int n = str.size();
	int total_per = fact(n);
	for(int i=0; i<total_per; i++){
		getPalindromicPer(i,n,str,"");
	}
}

int main(){
	string str;
	cin >> str;
	
	solution(str);
	
	return 0;
}







































bool isPalindrome(string str){
	int n = str.size();
	if(n == 0 || n == 1) return n;
	for(int i=0; i<=n/2; i++){
		if(str[i] != str[n-i-1]) return false;
	}
	return true;
}

int fact(int n){
	if(n == 1) return 1;
	return n*fact(n-1);
}
