#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int s,l;
		cin>>s>>l;
		if(s == 0) cout<<"Liquid";
		else if(l == 0) cout<<"Solid";
		else cout<<"Solution";
		cout<<"\n";
	}

	return 0;
}
