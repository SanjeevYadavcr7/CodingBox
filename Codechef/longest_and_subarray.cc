#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int prod;
		for(int i=0;;i++){
			prod = pow(2,i);
			if(prod >= n){
				prod = pow(2,i-1);
				break;
			} 
		}
		if(n == 1 || n == 2) cout<<1;
		else if(n%2 == 0) cout<<n-prod;
		else cout<<n-prod+1;
		cout<<"\n";
	}

	return 0;
}
