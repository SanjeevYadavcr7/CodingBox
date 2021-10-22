#include<iostream>
using namespace std;
#define M 10e9+7 

int stepPerms(int n){
	int ans = 0;
	if(n == 0) return 1;
	if(n<0) return 0;
	ans = stepPerms(n-1)+ stepPerms(n-2) + stepPerms(n-3);
	return ans;
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n; 
		cout<<stepPerms(n)<<endl;	
	}
	return 0;
}
