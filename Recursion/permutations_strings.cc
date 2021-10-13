#include <iostream>
using namespace std;

void printPermutations(string str, string ans){
	if(str.length() == 0){
		cout<<ans<<endl;
		return;
	}	
	
	for(int i=0;i<str.length();i++){
		string new_str = str;
		string temp = "";
		temp += new_str[i]; 
		new_str.erase(i,1);
		printPermutations(new_str, ans+temp);
	}
	return;
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
 	return 0;   
}
