#include<bits/stdc++.h>
using namespace std;

bool isValid(string str){
	int cnt = 0;
	for(char ch : str){
		if(ch == '(') cnt++;
		else if(ch == ')') cnt--;
		if(cnt < 0) return false;	
	}
	
	return cnt == 0;
}

void removeInvalidParenthesis(string str){
	vector<string> ans;
	unordered_set<string> hash_box;
	bool found = false;
	
	queue<string> Q;
	Q.push(str);
	
	while(!Q.empty()){
		string curr = Q.front();
		Q.pop();
		
		if(isValid(curr)){
			ans.push_back(curr);
			found = true;
		}
		
		if(found) continue;
		
		for(int i=0; i<curr.size(); i++){
			if(curr[i] != '(' && curr[i] != ')') continue;
			string temp = curr.substr(0,i) + curr.substr(i+1);
			if(hash_box.find(temp) == hash_box.end()){
				Q.push(temp);
				hash_box.insert(temp);
			}
		}
	}
	
	return ans;
}

int main(){
	string str;
	cin >> str;
	
	removeInvalidParenthesis(str);
	
	
	return 0;
}
