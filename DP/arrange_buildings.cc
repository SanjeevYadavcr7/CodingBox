#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll getTotalBuildings(int n){
	int b = 1, s = 1;
	for(int i=2;i<=n;i++){
		int temp_s = b;
		b += s;
		s = temp_s;
	}
	b += s;
	ll ans = b*b;
	return ans;
}

int main(){
	int n;
	cin>>n;
	
	ll buildings = getTotalBuildings(n);
	cout<<buildings<<"\n";
	
	return 0;
}
