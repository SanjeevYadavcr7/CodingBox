#include<bits/stdc++.h>
using namespace std;

void diffConsecutiveAlphbets(string str){
	int n = str.length();
	string ans = "";
	ans += str[0];
	for(int i=1;i<n;i++){
		int diff = str[i] - str[i-1];
		string ch_diff = to_string(diff);
		ans += ch_diff;
		ans += str[i];
	}
	cout<<ans<<endl;
}

int main(){
	string str;
	cin>>str;
	diffConsecutiveAlphbets(str);
	return 0;
}


