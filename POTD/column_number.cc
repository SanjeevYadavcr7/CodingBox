#include<bits/stdc++.h>
using namespace std;

    string convertToTitle(int columnNumber) {
        string title = "";
        while(columnNumber > 0){
            int rem = columnNumber%26;
            
            char curr_ch;
            if(rem == 0) curr_ch = 'Z';
            else curr_ch = 'A' + (rem-1);
            
            title = curr_ch + title;
            
            columnNumber /= 26;
            if(rem == 0) columnNumber--;
        }
        return title;
    }

int main(){
    int n; 
    cin >> n;
    
    string title = convertToTitle(n);
    cout << title << "\n";
 
    return 0;
}