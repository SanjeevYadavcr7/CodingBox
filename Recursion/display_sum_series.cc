#include<iostream>
using namespace std;

int max_num = 5;

int series_sum(int n){
	if(n == 0) return 0;
	int sum = n + series_sum(n-1);
	cout<<n;
	if(n != max_num) cout<<" + ";
	return sum;
}

int main(){
	int n;
	cin >> n;
	int sum = series_sum(n);		
	cout<<" = "<<sum<<endl;
	return 0;
}
