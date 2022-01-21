#include<iostream>
using namespace std;

void displaySubsequence(string str, string ans){
	if(str.length() == 0) return;
	
	string temp = ans+str[0];
	string new_str = str.substr(1);
	displaySubsequence(new_str,temp);
	displaySubsequence(new_str,ans);
}

int main(){
	string str;
	cin>>str;
	
	displaySubsequence(str, "");

	return 0;
}
