#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> arr) {
    for(auto i : arr) {
        for(int j : i) cout << j << " ";
        cout << endl; 
    }
}

vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for(int i=0; i<numRows; i++) {
            vector<int> rows; 
            if(i == 0) rows.push_back(1);
            else {
                for(int j=0; j<=i; j++) {
                    if(j == 0 || j == i) rows.push_back(1);
                    else rows.push_back(triangle[i-1][j]+triangle[i-1][j-1]);
                }
            }
            triangle.push_back(rows);
        }
        return triangle;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> triangle = generate(n);
    display(triangle);

    return 0;
}