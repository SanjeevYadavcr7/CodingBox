#include<iostream>
using namespace std;

void printPattern(int n){
	int max_spaces = n/2;
	for(int i=0;i<n;i++){
		if(i == max_spaces){
			for(int stars=0;stars<n;stars++) cout<<"* ";
		}
		else{
			for(int spaces=0;spaces<max_spaces;spaces++) cout<<"  ";
			if(i<max_spaces) for(int stars=0;stars<=i;stars++) cout<<"* ";
			else for(int stars=0;stars<n-i;stars++) cout<<"* ";
		}
		cout<<"\n";
	}
}

int main(){
	int n;
	cin>>n;
	printPattern(n);
	return 0;
}
