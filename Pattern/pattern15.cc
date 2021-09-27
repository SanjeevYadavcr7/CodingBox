#include<iostream>
using namespace std;

void printPattern(int n){
	int mid = n/2,spaces=mid,space2;
	for(int i=0;i<n;i++){
		if(i<=mid){
			for(int j=spaces;j>0;j--)cout<<"  ";
			int cnt = i;
			for(int j=0;j<=2*i;j++){
				if(j<=i){
					cnt += 1;
					cout<<cnt<<" ";	
				}
				else{
					cnt -= 1;
					cout<<cnt<<" ";
				}
			}
			cout<<"\n";
			spaces -= 1;
			space2 = 2*i-1;
		}
		else{
			for(int j=0;j<=spaces+1;j++)cout<<"  ";
			int cnt = n-i-1;
			for(int j=0;j<space2;j++){
				if(j<=space2/2){
					cnt += 1;
					cout<<cnt<<" ";
				}
				else{
					cnt -= 1;
					cout<<cnt<<" ";
				}
			}
			
			cout<<"\n";
			spaces += 1;
			space2 -= 2;
		}
	}
}

int main(){
	int n;
	cin>>n;
	printPattern(n);
	return 0;
}
