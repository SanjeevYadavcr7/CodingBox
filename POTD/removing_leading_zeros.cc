#include<bits/stdc++.h>
using namespace std;

string newIPAdd(string s){
	int i = 0, n = s.length();
	string new_ip = "";
	
	while(s[i] == '0') i++;
	if(s[i] == '.') new_ip += '0';
	
	while(i<n){
		if(s[i] == '.'){
			new_ip += '.';
			i++;
			while(s[i] == '0') i++;
			if(i == n) s[i] += '0';
		}
		if(s[i] == '.') new_ip += '0';
		else{
			new_ip += s[i];
			i++;
		}
	}
	return new_ip;
}

int main(){
	string ip_add;
	cin >> ip_add;
	
	string new_IP = newIPAdd(ip_add);
	cout << new_IP << "\n";
	
	return 0;
}
