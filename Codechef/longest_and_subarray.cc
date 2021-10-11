#include<iostream>
#include<math.h>
using namespace std;

int solve(int n){
	
	if(n == 1) return 1;
	int gap = 1;
	while(gap*2 <= n) gap *= 2;
	
	if(gap == n) return gap/2;
	int diff = n-gap+1;
	int ans = max(diff, gap/2);
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans = solve(n);
		cout<<ans<<"\n";
	}

	return 0;
}
