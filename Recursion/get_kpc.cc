#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string str, string ans){
   if(str.length() == 0){
   		cout<<ans<<" ";
   		return;
   }
   int index = str[0] - '0';
   string temp = codes[index];
   string new_str = str.substr(1);
   for(int i=0;i<temp.length();i++){
		char ch = temp[i];
		string temp_ans = ans+ch;
		printKPC(new_str, temp_ans);		
   }
   return;
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
	return 0;
}
