#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
	unordered_map<int, vector<string>> words;
	bool isEqual(string str, string word){
		for(int i=0; i<str.size(); i++){
			if(word[i] == '.') continue;
			if(word[i] != str[i]) return false;
		}
		return true;
	}
	public:	
    WordDictionary() {}
    
    void addWord(string word) {
        words[word.size()].push_back(word);
    }
    
    bool search(string word) {
    	for(auto &&str : words[word.size()]){
    		if(isEqual(str,word)) return true;
    	}
    	return false;
    }
};

int main(){
	int n;
	cin >> n;	
	vector<string> initString = {"WordDictionary","addWord","addWord","addWord","search","search","search","search"};
	vector<string> commands = {"","bad","dad","mad","pad","bad",".ad","b.."};
	
	WordDictionary* obj;
	for(int i=0; i<n; i++){
		if(initString[i] == "WordDictionary"){
			obj = new WordDictionary();
			cout << "null ";
		} 
		else if(initString[i] == "addWord"){
			string word = commands[i];
			obj->addWord(word);
			cout << "null ";
		} 
		else if(initString[i] == "search"){
			string word = commands[i];
			bool found = obj->search(word);
			if(found) cout << "true ";
			else cout << "false ";
		}
	}
	cout << "\n";
	
	return 0;
}


