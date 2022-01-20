#include<iostream>
using namespace std;

int binary_to_decimal(string str){
	int n = str.length(), ans = 0, j = 0;
	for(int i=n-1; i>=0; i--){
		if(str[i] == '1') ans += (1<<j);
		j++;
	}
	return ans;
}

int main(){
	string str;
	cin >> str;
	
	int num = binary_to_decimal(str);
	cout << num << "\n";
	
	return 0;
}

