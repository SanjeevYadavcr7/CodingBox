#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {

    int i=0;
    reverse(s.begin(),s.end());

    while(i<s.length() && s[i]==' ') s.erase(s.begin());
    
    i=s.length()-1;
    while(i>=0 && s[i]==' '){
        s.erase(s.begin()+i);
        i--;
    }

    for(int i=0; i<s.length(); i++){
        int j=i;
        while(j<s.length() && s[j] != ' '){
            j++;
        }
        reverse(s.begin()+i,s.begin()+j);
        i=j;
    }

    i=1;
    while(i<s.length()){
        if(s[i]==' ' && s[i+1]==' ') s.erase(s.begin()+i);
        else i++;
    }
    return s;
}

int main(){
    string str;
    getline(cin,str);
    
    cout << reverseWords(str) << "\n";

    return 0;
}