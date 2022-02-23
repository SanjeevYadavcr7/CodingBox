#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
	int n = str.size();
	if(n == 0) return false;
	if(n == 1) return true;
	for(int i=0; i<=n/2; i++){
		if(str[i] != str[n-i-1]) return false;
	}
	return true;
}

void display(vector<string>& arr){
	
	for(string str : arr){
		if(str.size() == 0) continue;
		cout << "(" << str << ") ";
	} 
	cout << "\n";
}

void getPartitions(string str, vector<string>& arr){
	if(str == ""){
		display(arr);
		return;
	}
	
	for(int i=0; i<str.size(); i++){
		string res = str.substr(0,i+1);
		if(isPalindrome(res)){
			string new_str = (i != str.size()-1) ? str.substr(i+1) : "";
			arr.push_back(res);
			//cout << "Res = " << res << " | New str = " << new_str << "\n";
			getPartitions(new_str,arr);
			arr.pop_back();
		}
	}
}

void solution(string str, string asf){
	int n = str.size();
	vector<string> arr(n);
	
	getPartitions(str,arr);
}

int main(){
	string str;
	cin >> str;
	solution(str,"");
	
	return 0;
}

















