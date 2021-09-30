#include<iostream>
using namespace std;

void convertToBase(int num, int base){
	if(num == 0) return;
	int rem = num % base;
	convertToBase(num/base, base);
	if(rem<10) cout<<rem;
	else{
		char ch = (rem-10)+'A';
		cout<<ch;
	} 
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<"Enter number and base = ";
		int base, num;
		cin >> num >> base;
		convertToBase(num, base);  	
		cout<<endl;
	}
	
	return 0;
}
