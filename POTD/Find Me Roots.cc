#include<bits/stdc++.h>
using namespace std;

bool canBeSolved(int a, int b, int c){
	int exp_val = b*b - (4*a*c);
	cout << "\nVal = " << exp_val;
	if(exp_val >= 0){
		int root = sqrt(exp_val);
		return (root * root == exp_val);
	}
	return false;
}

int main(){	
	int t;
	int a,b,c;
	int can_solve = 0;
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		if(canBeSolved(a,b,c)) can_solve++;
	}
	cout << can_solve << "\n";

	return 0;
}
