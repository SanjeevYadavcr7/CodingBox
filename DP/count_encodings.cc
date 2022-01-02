#include<bits/stdc++.h>
using namespace std;

int countEncodings(string str){
	if(str[0] == '0') return 0;
	int cnt = 1;
	int len = str.length();
	
	for(int i=0;i<len;i++){
		int num = str[i] - '0';
		if(num == 0){
			cnt -= 1;
			break;
		} 
	}
	
	//cout<<"Cnt = "<<cnt<<"\n";
	
	for(int i=0;i<len-1;i++){
		string temp = "";
		temp += str[i];
		temp += str[i+1];
		if(temp[0] != '0'){
			int index = stoi(temp);
			if(index <= 26) cnt++;
		}
	}
	return cnt;
}

int main(){
	string str;
	cin>>str;
	
	int cnt = countEncodings(str);
	cout<<cnt<<"\n";
	
	return 0;
}
