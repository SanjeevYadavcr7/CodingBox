#include<bits/stdc++.h>
using namespace std;

 vector<string> cellsInRange(string s) {
        vector<string> cells;
        char col1 = s[0], col2 = s[3];
        char row1 = s[1], row2 = s[4];
        for(char col = col1; col <= col2; col++){
            for(char row = row1; row <= row2; row++){
                string cell = "";
                cell += col;
                cell += row;
                cells.push_back(cell);
            }
        }
        return cells;
    }

int main(){
    string str;
    cin >> str;

    vector<string> cells = cellsInRange(str);
 
    return 0;
}