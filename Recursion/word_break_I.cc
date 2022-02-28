#include<bits/stdc++.h>
using namespace std;

bool isInDict(string word, vector<string>& dict){
	for(string curr_word : dict){
		if(curr_word == word) return true;
	}
	return false;
}

void display(vector<string>& sentence){
	for(string word : sentence) cout << word << " ";
	cout << "\n";
}

void printPossibleSentences(vector<string>& dict, string str, vector<string>& sentence){
	if(str.size() == 0){
		display(sentence);
		return;
	}
	
	for(int i=0; i<str.size(); i++){
		string left = str.substr(0,i+1);
		if(isInDict(left,dict)){
			sentence.push_back(left);
			string right = str.substr(i+1);
			printPossibleSentences(dict,right,sentence);
			sentence.pop_back();
		}
	}
}

int main(){
	int n;
	string str;
	cin >> n;
	vector<string> dict(n);
	for(int i=0; i<n; i++) cin >> dict[i];
	cin >> str;
	
	vector<string> sentence;
	printPossibleSentences(dict,str,sentence);
	
	return 0;
}
