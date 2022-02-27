#include<bits/stdc++.h>
using namespace std;

bool hasPrefix(string word, string pref){
	int n = word.size(), m = pref.size();
	if(m > n) return false;
	for(int i=0; i<m; i++){
		if(word[i] != pref[i]) return false;
	}
	return true;
}

int prefixCount(vector<string>& words, string pref) {
	int n = words.size(), cnt = 0;
	for(int i=0; i<n; i++){
		string str = words[i];
		if(hasPrefix(str,pref)) cnt++;
	}
	return cnt;
}

int main(){
	int n;
	string prefix;
	cin >> n;
	vector<string> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];	
	cin >> prefix;
	
	int prefix_cnt = prefixCount(arr,prefix);
	cout << prefix_cnt << "\n";
	
	return 0;
}
