#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){

    if(s.length() == 0){
    	vector<string> temp{{""}};
    	return temp;
    }
    char ch = s[0];
    string str = s.substr(1,s.length()-1);
    vector<string> temp = gss(str);
    
	/*    int n = ans.size();
	for(int x=0;x<n;x++){
		string temp_string = s[0]+ans[x];
		ans.push_back(temp_string);
	}
	*/
	vector<string> ans;
	for(string i : temp) ans.push_back(""+i);
	for(string i : temp) ans.push_back(ch+i);
    
    return ans;
}

int main(){
    string s;
    cout<<"Enter String = ";
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
