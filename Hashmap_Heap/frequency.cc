#include<bits/stdc++.h>
using namespace std;

char getMaxCharCount(string str){
	int n = str.length();
	int max_cnt = 0;
	char max_char;
	map<char,int> words_freq;
	for(int i=0;i<n;i++){
		char ch = str[i];
		words_freq[ch]++;
		if(words_freq[ch] > max_cnt){
			max_cnt = words_freq[ch];
			max_char = ch;
		}
	}
	return max_char;
}

int main(){
	string str;
	cin>>str;
	
	char max_char = getMaxCharCount(str); 
	cout<<max_char<<endl;
	
	return 0;
}
