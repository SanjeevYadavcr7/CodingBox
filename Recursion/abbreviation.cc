#include<iostream>
using namespace std;

void getAbbreviation(string str, string asf, int count, int pos){
	if(pos == str.length()){
		string ans = asf + ((count>0) ? to_string(count) : ""); 
		cout << ans << "\n";
		return;
	}
	
	string temp = asf + ((count>0) ? to_string(count) : "") + str[pos];
	getAbbreviation(str,temp,0,pos+1);
	getAbbreviation(str,asf,count+1,pos+1);
}

int main(){
	string str;
	cin >> str;
	getAbbreviation(str,"",0,0);

	return 0;
}
