#include<bits/stdc++.h>
using namespace std;

int countEncdings(string str){
	if(str[0] == '0') return 0;
	
	int len = str.length();
	int dp[len];
	dp[0] = 1;
	for(int i=1;i<len;i++){
		if(str[i-1] == '0' && str[i] == '0') dp[i] = 0;
		else if(str[i-1] == '0' && str[i] != '0') dp[i] = dp[i-1];
		else if(str[i-1] != '0' && str[i] == '0'){
			int num = str[i-1] - '0';
			if(num < 3) dp[i] = (i>1) ? dp[i-2] : 1;
			else dp[i] = 0;
		}
		else{
			int num = stoi(str.substr(i-1,2));
			if(num <= 26) dp[i] = ((i>1) ? dp[i-2] : 1) + dp[i-1];
			else dp[i] = dp[i-1];
		}
	}
	return dp[len-1];
}

int main(){
	string str;
	cin>>str;
	
	int cnt = countEncdings(str);
	cout<<cnt<<"\n";
	
	return 0;
}
