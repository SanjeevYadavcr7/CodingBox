#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p){
        vector<int> ans;
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        int n = s.size(), w = p.size();
		        
        if(n < w) return ans;
		
		int l = 0, r = 0;
		while(r < w){
			mp1[s[r]-'a'] += 1;
			mp2[p[r]-'a'] += 1;
			r++;
		}        
		r--;
		
		while(r < n){
			if(mp1 == mp2) ans.push_back(l);
			r += 1;
			if(r != n) mp1[s[r]-'a'] += 1;
			mp1[s[l]-'a'] -= 1;
			l += 1;
 		}
        return ans;
}

int main(){
	string str, ptr;
	getline(cin,str);
	getline(cin,ptr);
	
	vector<int> arr = findAnagrams(str,ptr);
	for(int i : arr) cout << i << " ";
	cout << "\n";
	
	return 0;
}
