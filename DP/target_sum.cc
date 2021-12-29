#include <bits/stdc++.h>
using namespace std;

void targetSumSubset(int n, vector<int> arr, int tar) {
	bool dp[n+1][tar+1] = {false};
	for(int i=0;i<=n;i++) dp[i][0] = true;
	for(int j=1;j<=tar;j++){
		if(j == arr[0]) dp[1][j] = true;
	}
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=tar;j++){
			if(dp[i-1][j]) dp[i][j] = true;
			int new_col = j - arr[i-1];
			if(new_col >= 0 && dp[i-1][new_col]) dp[i][j] = true; 
		}	
	}
	
	if(dp[n][tar]) cout<<"true\n";
	else cout<<"false\n";
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int tar;
  cin >> tar;
  targetSumSubset(n, arr, tar);
  
  return 0;
}
