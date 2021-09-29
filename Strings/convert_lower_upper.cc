#include<iostream>
// #include<string>
using namespace std;
const int limit = 32;

void convertLowerUpper(string str){
	int n = str.length();
	for(int i=0;i<n;i++){
		char ch = str[i];
		if(isupper(ch)) str[i] = str[i] | limit;
		else str[i] = str[i] & ~limit;
	}
	cout<<str<<"\n";
}

int main(){
	string str;
	cin>>str;
	convertLowerUpper(str);
	return 0;
}


