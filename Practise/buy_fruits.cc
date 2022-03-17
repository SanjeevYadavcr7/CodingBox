#include<bits/stdc++.h>
using namespace std;

void solve(int x, vector<int>& price){
    int min_num = INT_MAX, sec_min_num = INT_MAX;
    for(int i=0; i<3; i++){
        if(min_num > price[i]){
            sec_min_num = min_num;
            min_num = price[i];
        }
        else if(sec_min_num > price[i]) sec_min_num = price[i];
    }
    int ans = min_num*(x-1) + sec_min_num;
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        vector<int> price(3,0);
        cin >> x;
        for(int i=0; i<3; i++) cin >> price[i];
        solve(x,price); 
    }
 
    return 0;
}