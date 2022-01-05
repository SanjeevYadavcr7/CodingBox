#include<bits/stdc++.h>
using namespace std;

void displaySubsequence(string str){
	int n = str.length();
	vector<vector<int>> dp(3, vector<int>(n+1,0));
	
	for(int j=1;j<=n;j++){
		char curr_char = str[j-1];
		if(curr_char == 'a'){
			dp[0][j] = 2 * dp[0][j-1] + 1;
			dp[1][j] = dp[1][j-1];
			dp[2][j] = dp[2][j-1];
		} 
		else if(curr_char == 'b'){
			dp[0][j] = dp[0][j-1];
			dp[1][j] = 2 * dp[1][j-1] + dp[0][j-1];
			dp[2][j] = dp[2][j-1];
		} 
		else if(curr_char == 'c'){
			dp[0][j] = dp[0][j-1];
			dp[1][j] = dp[1][j-1];
			dp[2][j] = 2 * dp[2][j-1] + dp[1][j-1];
		} 
	}
	
	int ans = dp[2][n];
	cout<<ans;
}

int main(){
	string str;
	cin>>str;
	
	displaySubsequence(str);
	cout<<"\n";
	
	return 0;
}
