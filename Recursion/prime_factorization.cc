#include<iostream>
using namespace std;

void primeFactors(int n){
	int i = 2;
	if(n == 1) return;
	while(n%i != 0) i++;
	cout<<i<<" ";
	primeFactors(n/i);
}

int gcd(int n, int m){
	if(m == 0) return n;
	return gcd(m, n%m);
}

int main(){
	int n, m;
	cin >> n;
	primeFactors(n);
	cout<<"\n";
	cin >> m;
	int gcd_num = gcd(n, m);
	cout<<gcd_num<<endl;
	return 0;
}

