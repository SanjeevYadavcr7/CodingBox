#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
	int n = num.size();
	stack<char> chars;
	string min_num = "";
	
	chars.push(num[0]);
	
	for(int i=1; i<n; i++){
		char ch = num[i];
		if(k<0){
			if(chars.empty() && ch == '0') continue;
			chars.push(ch);
		}
		if(chars.empty()){
			if(ch != '0') chars.push(ch);
		} 
			int curr_num = ch - '0';
			int prev_num = chars.top() - '0';
			while(!chars.empty() && k>0 && curr_num < prev_num){
				chars.pop();
				k--;
				prev_num = (!chars.empty()) ? chars.top() - '0' : -1;
			}
			if(chars.empty() && ch == '0') continue;
			chars.push(ch);
		}
	}
	
	while(k-- && !chars.empty()) chars.pop();
	
	if(chars.empty()) return "0";
	
	while(!chars.empty()){
		min_num = chars.top() + min_num;
		chars.pop();
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
