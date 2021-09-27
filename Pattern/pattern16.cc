#include<iostream>
using namespace std;

void printPattern(int n){
	int spaces = n*2-3;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++) cout<<j<<" ";
		for(int j=1;j<=spaces;j++) cout<<"  ";
		for(int j=i;j>=1;j--){
			if(i==n && j==n)continue;
			cout<<j<<" ";
		} 
		spaces -= 2;
		cout<<"\n";
	}
}

int main(){
	int n;
	cin>>n;
	printPattern(n);
	return 0;
}
