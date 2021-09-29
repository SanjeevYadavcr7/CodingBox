#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	if(n == 1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i == 0) return false;
	}
	return true;
}


void removePrimes(vector<int> &arr, int n){
	vector<int>::iterator i = arr.end();
	while(i != arr.begin()){
		--i;
		if(isPrime(*i)) arr.erase(i);
	}
}

int main(){
	int n, x;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		cin>>x;
		arr.push_back(x);
	}
	removePrimes(arr, n);
	for(int i : arr) cout<<i<<" ";
	cout<<"\n";
	return 0;
}
