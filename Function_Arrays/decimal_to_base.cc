#include<bits/stdc++.h>
using namespace std;

string solve(int num, int base){
	string ans = "";
	while(num >= base){
		int rem = num % base;
		char ch = rem + '0';
		ans += ch;
		num = num/base;
	}
	char ch = num + '0';
	ans += ch;
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	int n, base;
	cin>>n>>base;
	string ans = solve(n,base);
	cout<<ans<<"\n";
	return 0;
}
