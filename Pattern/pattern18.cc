#include<iostream>
using namespace std;

void printPattern(int n){
	int max_spaces = n/2;
	int max_stars = n;
	for(int i=0;i<n;i++){
		if(i == max_spaces) for(int stars = 0 ; stars < max_stars; stars++) cout<<"*\t";
		else{
			if(i == 0){
				for(int star=0;star<max_spaces;star++) cout<<"*\t";
			}
			else{
				if(i>max_spaces){
					cout<<"*\t";
					for(int space=0;space<max_spaces-1;space++) cout<<"\t";
					if(i == n-1) for(int star=0;star<max_spaces;star++) cout<<"*\t";
				}
				else{
					for(int space=0;space<max_spaces;space++) cout<<"\t";
				}
			}
			cout<<"*\t";
			if(i<max_spaces){
				for(int space=0;space<max_spaces-1;space++) cout<<"\t";
				cout<<"*";
			}
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
