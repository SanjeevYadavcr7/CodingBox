#include<iostream>
#include<math.h>
using namespace std;

int solve(int x){
	if(x == 0) return 1;
	int i = 1, res;
	int r = pow(2,i) - 1;
	while(x >= r){
		i++;
		res = r;
		r = pow(2,i) - 1;
		if(r>x){
			i--;
			break;
		} 
	}
	return res+1;
}

int main(){	
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		int ans = solve(x);
		cout<<ans<<"\n";
	}
	
	return 0;
}
