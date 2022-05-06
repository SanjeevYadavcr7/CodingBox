#include<bits/stdc++.h>
using namespace std;

// More Optimized Solution 
string removeDuplicates(string s, int k) {  
	int n = s.size();
	string res = "";
	vector<pair<char,int>> stk;
	
	for(char ch : s) {
		if(stk.empty() || stk.back().first != ch) stk.push_back({ch,1});
		else stk.back().second++;
		
		if(stk.back().second == k) stk.pop_back();
	}
	
	for(auto x : s) res.append(x.second,x.first);
	return res;
}


// Approach: using stack | TC: O(N) | SC: O(N)
string removeDuplicates(string s, int k) {    
		string res = "";
        int n = s.size();
        stack<pair<char,int>> stk;
        
        for(char ch : s) {
            if(stk.empty() || stk.top().first != ch) stk.push({ch,1});
            else stk.push({ch,stk.top().second+1});

            if(stk.top().second >= k) {
                int cnt = k;
                while(cnt--) stk.pop(); 
            }
        }

        while(!stk.empty()) {
            res += stk.top().first;
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
}

int main() {
	int k;
	string str;
	cin >> str >> k;
	
	string minimal_str = removeDuplicates(str,k);
	cout << minimal_str << endl;

	return 0;
}
