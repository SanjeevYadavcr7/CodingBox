#include<iostream>
using namespace std;

int digitsSum(int n){
	if(n == 0) return 0;
	int sum = n%10 + digitsSum(n/10);
	cout<<n%10;
	return sum;
}

int main(){
	int n;
	cin >> n;
	cout<<"Sum of digits of ";
	int sum = digitsSum(n);
	cout<<" is "<<sum<<endl;
	return 0;
}
