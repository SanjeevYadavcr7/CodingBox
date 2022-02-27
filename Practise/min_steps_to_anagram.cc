#include<bits/stdc++.h>
using namespace std;

int minSteps(string s, string t){
	vector<int> hash1(26,0);
	vector<int> hash2(26,0);
	int min_steps = 0;
	
	for(char ch : s) hash1[ch-'a'] += 1;
	for(char ch : t) hash2[ch-'a'] += 1;
	
	for(int i=0; i<26; i++) min_steps += abs(hash1[i] - hash2[i]);
	
	return min_steps;
}

int main(){
	string s,t;
	cin >> s >> t;
	
	int min_steps = minSteps(s,t);
	cout << min_steps << "\n";
	
	return 0;
}
