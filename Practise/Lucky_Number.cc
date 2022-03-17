#include<iostream>
using namespace std;

bool lucky(int a, int b, int c){
	if(a == 7 || b == 7 || c == 7)return true;
	else return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(lucky(a,b,c)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
