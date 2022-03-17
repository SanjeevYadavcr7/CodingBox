#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Recursion

int idx = 0;
int scoreOfParentheses(string str){
	int score = 0;
	while(idx < str.size()){
		char f = str[idx++];
		char s = str[idx];
		if(f == '('){
			if(s == ')'){
				score++;
				idx++;
			}
			else score += 2*scoreOfParentheses(str);
		}
		else return score;
	}
	return score;
}



// Approach 2: Using Stack
int scoreOfParentheses(string str){
	stack<int> stk;
	int score = 0;
	for(char ch : str){
		if(ch == '('){
			stk.push(score);
			score = 0;
		}
		else{
			score = stk.top() + max(2*score,1);
			stk.pop();
		}
	}
	return score;
}


int main(){
	string str;
	cin >> str;
	
	int score = scoreOfParentheses(str);
	cout << score << "\n";
	
	return 0;
}
