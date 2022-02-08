#include<bits/stdc++.h>
using namespace std;

int getNum(int num){
	int ans = 0;
	while(num > 0){
		ans += (num%10);
		num /= 10;
	}
	return ans;
}	

int addDigits(int num){
	while(num > 9) num = getNum(num);
	return num;
}

int main(){
	int num;
	cin >> num;
	
	int ans = addDigits(num);
	cout << ans << "\n";
	
	return 0;
}
