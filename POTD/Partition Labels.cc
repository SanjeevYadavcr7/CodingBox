#include<bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s){
	int n = s.size();
	vector<int> ans;
	unordered_map<char,int> mp;
	for(char ch : s) mp[ch] += 1;
	
	for(int i=0; i<n; i++){
		if(mp[s[i]] == 1){
			ans.push_back(1);
			mp[s[i]] = 0;
		}
		else{
			unordered_set<char> part;			
			char ch = s[i], temp;
			int len = 0;
			while(true){	
				while(i<n && mp[ch] > 0){
					part.insert(s[i]);
					mp[s[i]] -= 1;
					len++;
					i++;	
				}
				bool flag = true;
				for(auto j : part){
					if(mp[j] > 0){
						ch = j; 
						flag = false;
						break;
					}
				}
				if(flag) break;
			}
			ans.push_back(len);
			i--;
		}
	}
	return ans;
}

int main(){
	string str;
	cin >> str;
	
	vector<int> partition = partitionLabels(str);
	for(int &i : partition) cout << i << " ";
	cout << "\n";
	
	return 0;
}
