#include<bits/stdc++.h>
using namespace std;
 
int titleToNumber(string columnTitle) {
    int n = columnTitle.length();
    int title_num = 0;

    for(int i=n-1, k=0; i>=0; i--,k++){
        char curr_char = columnTitle[i];
        int curr_num = (curr_char - 'A') + 1;
        title_num += pow(26,k)*curr_num;
    }
    return title_num;
}

int main(){
    string str;
    cin >> str;

    int num = titleToNumber(str);
    cout << num << "\n";
 
    return 0;
}