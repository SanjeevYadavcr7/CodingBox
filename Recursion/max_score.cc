#include<bits/stdc++.h>
using namespace std;

int solution(vector<string> &words, vector<int> farr, vector<int> &score, int i){
	
	if(i == words.size()) return 0;
	
	int without_curr_word = solution(words, farr, score, i+1);
	
	int with_curr_word = 0, curr_word_score = 0;
	bool can_proceed = true;
	string curr_word = words[i];
	
	for(char ch : curr_word){
		int curr_i = ch - 'a';
		if(farr[curr_i] > 0) farr[curr_i]--;
		else{
			can_proceed = false;
			break;
		} 		
		curr_word_score += score[curr_i];
	}
	
	if(can_proceed) with_curr_word = curr_word_score + solution(words, farr, score, i+1);
	 
	int res = max(with_curr_word,without_curr_word);
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<string> words;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		words.push_back(s);
	}
	int m;
	cin >> m;
	vector<char> alphabets;
	for(int i=0; i<m; i++){
		char ch;
		cin >> ch;
		alphabets.push_back(ch);
	}
	vector<int> score(26);
	for(int i=0; i<26; i++) cin >> score[i];
	
	vector<int> farr(26);
	for(char ch : alphabets){
		farr[ch - 'a']++;
	}
	
	int max_score = solution(words, farr, score, 0);
	cout << max_score << "\n";

	return 0;
}
