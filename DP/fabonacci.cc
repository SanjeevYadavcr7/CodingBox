#include<bits/stdc++.h>
using namespace std;

int fab(int n){
	if(n == 0 || n == 1) return n;
	
	int fabnm1 = fab(n-1);
	int fabnm2 = fab(n-2);
	int fabn = fabnm1 + fabnm2;
	return fabn;
}

int optimizedFab(int n, vector<int>& mem){
	if(n == 0 || n == 1) return n;
	
	if(mem[n]) return mem[n];
	
	int fabnm1 = fab(n-1);
	int fabnm2 = fab(n-2);
	int fabn = fabnm1 + fabnm2;
	
	mem[n] = fabn;
	
	return fabn;
}

int main(){
	int n;
	cin>>n;
	cout<<fab(n)<<"\n";
	
	vector<int> mem(n+1,0);
	cout<<optimizedFab(n,mem)<<"\n";
	
	return 0;
}
