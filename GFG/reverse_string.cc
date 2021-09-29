#include<bits/stdc++.h>
using namespace std;

class Solution{
	public: 
		string reverseWords(string S){
			vector<string> str;
			int n = S.length();
			string word = "";
			for(int i=0;i<n;i++){
				if(S[i] == '.'){
					word = word;
					str.push_back(word);
					str.push_back(".");
					word = "";
				}
				else word = word + S[i];
			}
			str.push_back(word);
			S = "";
			vector<string>::iterator it = str.end();
			while(it != str.begin()){
				--it;
				S = S+*it;
			}
			return S;
		}
};

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		Solution obj;
		cout<<obj.reverseWords(s)<<"\n";
	}
	return 0;
}
