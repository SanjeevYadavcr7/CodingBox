#include<bits/stdc++.h>
using namespace std;

void intializeMap(unordered_map<int,vector<string>>& digits_map) {
        int cnt = 0;
        char ch = 'a';
        for(int i=0; i<=7; i++) {
        	int range = (i+2 == 7 || i+2 == 9) ? 4 : 3;
            for(int j=0; j<range; j++) {
                string str;
                str += ch;
                digits_map[i+2].push_back(str);    
            	ch++;
            }
        }
}
    
vector<string> letterCombinations(string digits) {
	vector<string> res;
    int n = digits.size();
    unordered_map<int,vector<string>> digits_map;
        
        if(n == 0) return res;
        
        intializeMap(digits_map);
        for(int i=n-1; i>=0; i--) {
            int num = digits[i] - '0';
            if(res.size() == 0) res = digits_map[num];
            else {
                vector<string> ans;
                for(string ch : digits_map[num]) {
                    for(string str : res) ans.push_back(ch+str);
                } 
                res = ans;
            }
        }
        return res;
    }
    
int main() {
    string digits;
    cin >> digits;
    
    vector<string> res = letterCombinations(digits);
   	for(string str : res) cout << str << " "; cout << endl;
    
	return 0;
}
