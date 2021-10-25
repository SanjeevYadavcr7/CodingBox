#include<iostream>
using namespace std;
#define ll long long
#define M 1000000007

void solve(int x, int k){
	ll min, max;
	min = x*2;
	max = (x*k*(x*k-1));
	cout<<min<<" "<<max<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}
