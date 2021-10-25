#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k;
void solve(){
	cin>>n>>k;
	if(k == 0){
		cout<<"YES"<<endl<<"0"<<endl;;
		return;
	}
	if(k%2 == 0){
		cout<<"NO"<<endl;
		return;
	}
	ll sz = 0;
	for(ll i=31;i>=0;i--){
		if(((1<<i)&k) != 0){
			sz = i+1;
			break;
		}
	}
	k=(k+(1<<sz)-1)/2;
	cout<<"YES"<<endl;
	cout<<sz<<endl;
	int ans = 1;
	vector<int> a;
	for(int i=sz-2;i>=0;i--){
		if(((1<<i)&k) != 0){
			a.push_back(ans);
			ans += (1<<i);
		}
		else{
			ans -= (1<<i);
			a.push_back(ans);
		}
	}
	for(int i=sz-2;i>=0;i--) cout<<a[i]<<endl;
	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
