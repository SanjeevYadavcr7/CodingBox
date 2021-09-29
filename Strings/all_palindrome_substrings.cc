#include<iostream>
using namespace std;

bool isPalindrome(string str){
	int n = str.length();
	if(n == 1) return true;
	for(int i=0;i<n/2;i++){
		if(str[i] != str[n-i-1]) return false;
	}
	return true;
}

void printAllPalindrome(string str){
	int n = str.length();
	for(int i=0;i<n;i++){
		for(int j=1;j<=n-i;j++){
			string sub_string = str.substr(i,j);
			if(isPalindrome(sub_string)) cout<<sub_string<<"\n";
			// cout<<sub_string<<" | "<<isPalindrome(sub_string)<<"\n";
		}
	}
}

int main(){
	string str;
	cin>>str;
	printAllPalindrome(str);
	return 0;
}
