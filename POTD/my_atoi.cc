#include<bits/stdc++.h>
using namespace std;


int myAtoi(string s){
	int n = s.length(), i=0, sign = 1;
	while(s[i] == ' ') i++;
	if(s[i] == '-' || s[i] == '+'){
		if(s[i] == '-') sign = -1;
		i++;
	}
	
	long ans = 0;
	while(i<s.length() && (s[i] >= '0' && s[i] <= '9')){
		int digit = (s[i] - '0');
		ans = ans*10 + digit;
		if(ans >= INT_MAX) break;
		i++;	
	}
	
	if(sign == -1) ans *= -1;
	
	if(ans <= INT_MIN) return INT_MIN;
	else if(ans >= INT_MAX) return INT_MAX;
	
	return ans;
}	

int main(){
	string str;
	getline(cin,str);
	
	int num = myAtoi(str);
	cout << num << "\n";
	
	return 0;
}


