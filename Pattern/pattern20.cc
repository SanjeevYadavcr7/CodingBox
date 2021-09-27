#include<iostream>
using namespace std;

void printPattern(int n){
	int max_spaces = n-2;
	int inner_spaces=1;
	for(int i=0;i<n;i++){
		cout<<"* ";
		if(i<n/2 || i == n-1) for(int space=0;space<n-2;space++) cout<<"  ";
		else if(i == n/2){
			for(int space=0;space<n/2-1;space++) cout<<"  ";
			cout<<"* ";
			for(int space=0;space<n/2-1;space++) cout<<"  ";
			max_spaces=n/2-2;
		}
		else{
			for(int left_space=0;left_space<max_spaces;left_space++) cout<<"  ";
			cout<<"* ";
			for(int mid_space=0;mid_space<inner_spaces;mid_space++) cout<<"  ";
			cout<<"* ";
			for(int right_space=0;right_space<max_spaces;right_space++) cout<<"  ";
			// cout<<max_spaces<<" || "<<inner_spaces<<"\n";
			max_spaces -= 1;
			inner_spaces += 2;
		} 
		cout<<"*\n";
	}
}

int main(){
	int n;
	cin>>n;
	printPattern(n);
	return 0;
}
