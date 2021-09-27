#include<iostream>
using namespace std;

void printPattern(int n){
	int mid = n/2, max_stars=3, inner_space=n, max_space=n-4;
	for(int i=0;i<n;i++){
		if(i == 0) for(int stars=0;stars<n;stars++) cout<<"* "; 
		else if(i < mid){
			for(int space=0;space<i;space++) cout<<"  ";
			cout<<"* ";
			for(int space=0;space<max_space;space++) cout<<"  ";
			cout<<"*";
			max_space -= 2;
		}
		else if(i == mid){
			for(int space=0;space<i;space++) cout<<"  ";
			cout<<"*";
		}
		else{
			for(int space=0;space<n-i-1;space++) cout<<"  ";
			for(int stars=0;stars<max_stars;stars++) cout<<"* ";	
			max_stars += 2;
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
