#include<bits/stdc++.h>
using namespace std;

vector<int> countBits(int n){
	vector<int> bits(n+1);
	int flag = 0, k = 0;
	
	bits[0] = 0;
	for(int i=1; i<=n; i++){
		if(pow(2,k) == i){
			bits[i] = 1;
			flag = i;
			k++;
		} 
		else{
			bits[i] = bits[flag] + bits[i-flag];
		}
	}
	return bits;
}

int main(){	
	int n;
	cin >> n;
	
	vector<int> bits = countBits(n);
	for(int& i : bits) cout << i << " ";
	cout << "\n";
	
	return 0;
}
