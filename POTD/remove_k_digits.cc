#include<bits/stdc++.h>
using namespace std;

string strictlyDecreasing(string num){
	int n = num.size(), flag = -1, zeros = 0;
	string new_str = "";
	for(int i=1; i<n; i++){
		if(num[i] < num[i-1]){
			flag = i-1;
			break;
		}
	}
	
	if(flag == -1) flag = n-1;
	for(int i=0; i<n; i++){
		if(i == flag) continue;
		new_str += num[i];
		if(num[i] == '0') zeros++;
	}
	
	int new_str_size = new_str.size();
	if(zeros == new_str_size) return "0";
	
	int i=0;
	while(i < new_str_size && new_str[i] == '0') i++;
	return new_str.substr(i);
}

string removeKdigits(string num, int k) {
	int n = num.length();
	string min_num = "";
	
	if(n == k) return "0";
	
	while(k--){
		min_num = strictlyDecreasing(num);
		num = min_num;
	}
	return min_num;
}

int main(){
	int k;
	string num;
	cin >> num >> k;

	string max_num = removeKdigits(num,k);
	cout << max_num << "\n"; 
	
	return 0;
}
