#include<bits/stdc++.h>
using namespace std;

string ExcelColumn(int N){
	if(N <= 0) return "";
    if(N<27){
    	char ch = N-1 + 'A';
    	//cout << "Ch = " << ch << "\n";
        string ans = "";
        ans += ch;
        return ans;
	}
    
    string ans = "";
    int left = N-26;
    if(left > 0){
    	ans += "A" + ExcelColumn(left);
    }
    else{
    	ans += (N+'A');
    }
    return ans;
}

int main(){
	int n;
	cin >> n;
	
	string ans = ExcelColumn(n);
	cout << ans << "\n";
	
	return 0;
}
