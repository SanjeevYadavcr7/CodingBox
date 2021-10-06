#include<iostream>
#include<vector>
using namespace std;

vector<string> mp{{".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"}};

vector<string> getKpc(string str){
	
	if(str.length() == 0){
		vector<string> temp{{""}};
		return temp;
	}
	char ch = str[0];
	string temp_s = mp[ch-'0'];
	string rest = str.substr(1);
	vector<string> temp = getKpc(rest);
	
	vector<string> ans;
	for(char i : temp_s){
		for(string j : temp){
			string temp_r = "";
			temp_r += i;
			temp_r += j;
			ans.push_back(temp_r);
		}
	}
		
	return ans;
}


int main(){
	int cnt = 0;
	string str;
	cin>>str;
	vector<string> ans = getKpc(str);
	
	cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';

	return 0;
}
