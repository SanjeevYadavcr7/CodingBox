#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k){
	if(n == 1) return 0;
	int x = solve(n-1,k);
	int y = ( x + k ) % n;
	return y;
}

int main(){
	int n, k;
	cin >> n >> k;
	
	int ans = solve(n,k);
	cout << ans << "\n";
	
	return 0;
}
