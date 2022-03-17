#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n == 0 || n == 1) return n;
    return ((n&1) ? solve(n/2)+1 : solve(n/2));
}

int numberOfPairs(int n, vector<int> &arr) {
    int valid_pairs = 0;
    for(int i=0; i<n-1; i++){
        int res1 = solve(arr[i]);
        for(int j=i+1; j<n; j++){
            int res2 = solve(arr[j]);
            if(res1 == res2) valid_pairs++;
        }
    }
    return valid_pairs;
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> arr(n,0);
        for(int i=0; i<n; i++) cin >> arr[i];
        
        int ans = numberOfPairs(n,arr);
        cout << ans << "\n";
    }
    
    return 0;
}