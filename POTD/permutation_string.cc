#include<bits/stdc++.h>
using namespace std;

void display(vector<int> arr){
	for(int& i : arr) cout << i << " ";
	cout << "\n";
}

bool checkInclusion(string s1, string s2){
	int n = s1.length(), m = s2.length();
	
	vector<int> mp1(26,0);
	vector<int> mp2(26,0);
	
	for(char ch : s1) mp1[ch-'a'] += 1;
	for(int i=0; i<n; i++) mp2[s2[i]-'a'] += 1;
	if(mp1 == mp2) return true;
	
	//cout << "mp1[] = "; display(mp1);
	
	for(int i=n; i<m; i++){
		
		mp2[s2[i-n]-'a'] -= 1;
		mp2[s2[i]-'a'] += 1;
		if(mp1 == mp2) return true;
		//cout << "mp2[] = "; display(mp2);
	}
	return false;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	
	if(checkInclusion(s1,s2)) cout << "true\n";
	else cout << "false\n";	

	return 0;
}
