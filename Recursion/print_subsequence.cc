#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    if(ques.length() == 0){
    	return;
    }
    char ch = ques[0];
    string str = ques.substr(1);
    
    cout<<ch+str<<endl;
    printSS(str,ans);
    return;
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}
