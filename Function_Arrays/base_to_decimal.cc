#include<bits/stdc++.h>
using namespace std;

int solve(int num, int base){
	int ans=0, i=0;
	while(num != 0){
		int rem = num%10;
		ans += (rem * pow(base,i++));
		num /= 10;
	}	
	return ans;
}

int main(){
	int num, base;
	cin>>num>>base;
	int ans = solve(num, base);
	cout<<ans<<"\n";
	return 0;
}
