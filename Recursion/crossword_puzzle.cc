#include<bits/stdc++.h>
using namespace std;

vector<string> crosswordPuzzle(vector<string> crossword, string words) {

}

int main(){
	vector<string> crossword;
	for(int i=0;i<10;i++){
		string row;
		cin>>row;
		crossword.push_back(row);
	}
	string words;
	getline(cin, words);
	
	vector<string> ans = crosswordPuzzle(crossword, words);
	for(string row:ans) cout<<row<<endl;
		
	return 0;
}
