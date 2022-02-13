#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> wordSet;
	bool found = false;
	
	for(string str : wordList){
		if(str == endWord) found = true;
		wordSet.insert(str);
	}
	
	if(!found) return 0;
	
	queue<string> Q;
	Q.push(beginWord);
	int depth = 0;
	
	while(!Q.empty()){
		int size = Q.size();
		depth += 1;
		while(size--){
			string temp = Q.front();
			Q.pop();
			
			for(int i=0; i<temp.size(); i++){
				string curr = temp;
				for(char ch='a'; ch<='z'; ch++){
					curr[i] = ch;
					if(curr == temp) continue;
					if(curr == endWord) return depth+1;	
					
					if(wordSet.find(curr) != wordSet.end()){
						Q.push(curr);
						wordSet.erase(curr);
					}
				}
			}
		}
	}
	return 0;
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
