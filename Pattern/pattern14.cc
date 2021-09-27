#include<iostream>
using namespace std;

void printPattern(int n){
	for(int i=1;i<=10;i++)
		cout<<n<<"*"<<i<<"="<<n*i<<"\n";
}


int main(){
	int n;
	cin>>n;
	printPattern(n);
	return 0;
}
