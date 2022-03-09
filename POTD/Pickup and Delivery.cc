#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

int countOrders(int n){
    int res = 1;
    for(int i=1; i<=n; i++){
        res *= i;
        res %= M;
        res *= (2*i-1);
        res %= M;
    }
    return res;
}

//  int ans = 0;
    
//     void solve(string str, unordered_map<char,bool>& isPresent, string psf){
//         if(str.size() == 0){
//             ans++;
//             return;   
//         }
        
//         int n = str.size();
//         for(int i=0; i<n; i++){
//             string new_str = str.substr(0,i) + ((i+1 < n) ? str.substr(i+1) : "");
//             int k = str[i]-'0';
//             if(k%2 == 0){
//                 k += 1;
//                 char ch = k + '0';
//                 if(isPresent[ch]) continue;
//             }
//             isPresent[str[i]] = true;
//             solve(new_str,isPresent,psf+str[i]);    
//             isPresent[str[i]] = false;
//         }
//     }
    
//     int countOrders(int n) {
//         int pick_del = 2*n;
//         string str = "";
//         for(int i=0; i<pick_del; i++) str += to_string(i);

//         unordered_map<char,bool> isPresent;
//         solve(str,isPresent,"");
//         return ans;
//     }
    

int main(){
    int n; 
    cin >> n;
    
    int res = countOrders(n);
    cout << res << "\n";

    return 0;
}