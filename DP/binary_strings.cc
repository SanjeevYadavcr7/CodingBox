#include<bits/stdc++.h>
using namespace std;

void printBinaryStrings(int n){
	int beg0 = 1, beg1 = 1;
	for(int i=2;i<=n;i++){
		int temp0 = beg1;
		beg1 = beg0 + beg1;
		beg0 = temp0;
	}
	int total_valid_strings = beg0 + beg1;
	cout<<total_valid_strings<<"\n";
}

int main(){
	int n;
	cin>>n;
	
	printBinaryStrings(n);
	
	return 0;
}
