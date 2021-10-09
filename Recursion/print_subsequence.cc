#include <iostream>
using namespace std;

void printSS(string str, string ans){		
	if(str.length() == 0){
		cout<<ans<<"\n";
		return;
	} 
    char ch = str[0];
    string new_str = str.substr(1);
    ans += ch;
    printSS(new_str, ans);
    ans = ans.erase(ans.length()-1);
    printSS(new_str, ans);
	return;
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
	return 0;
}
