#include<bits//stdc++.h>
using namespace std;

bool isPowerOfTwo(int num){
	if(num < 1) return false;
	return ((num & num-1) == 0);
}

int main(){
	int n;
	cin >> n;
	
	if(isPowerOfTwo(n)) cout << "true";
	else cout << "false";
	
	return 0;
}
