#include<bits/stdc++.h>
using namespace std;
int ladder_length = INT_MAX;

/*
bool validWord(string prev, string curr){
	int cnt = 0;
	unordered_map<char,int> mp;
	
	for(char ch : prev) mp[ch] += 1;
	for(char ch : curr) mp[ch] -= 1;
	for(auto it : mp){
		if(it.second != 0) cnt ++;
	}
	
	if(cnt == 2) return true;
	return false;
}
*/

bool validWord(string prev, string curr){
	int n = prev.size(), m = curr.size(), cnt = 0;
	
	if(n != m) return false;
	for(int i=0; i<n; i++){
		if(prev[i] != curr[i]) cnt++;
		if(cnt > 1) return false;
		
	}
	return true;
}

void climbLadder(string prev, string end, vector<string>& wordList, unordered_map<string,bool>& vis, int len, string path){
	if(prev == end){
		cout << path << "->" << "\n";
		ladder_length = min(ladder_length,len);
		return;
	}
	
	for(string word : wordList){
		if(!vis[word] && validWord(prev,word)){
			cout << "Curr word = " << prev << " | Next word = "<< word <<"\n"; 
			vis[word] = true;
			climbLadder(word,end,wordList,vis,len+1,path+"->"+word);		
			vis[word] = false;
		}
	}
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_map<string,bool> vis;
	vis[beginWord] = true;
	climbLadder(beginWord,endWord,wordList,vis,1,beginWord);	
	if(ladder_length == INT_MAX) return 0;
	return ladder_length;
}

int main(){
	int n;
	string beg, end;
	
	cin >> beg >> end;
	cin >> n;
	vector<string> wordList(n,"");
	for(int i=0; i<n; i++) cin >> wordList[i];	
	
	int ladder_len = ladderLength(beg,end,wordList);
	cout << ladder_len << "\n";

	return 0;
}
